#pragma once

class Q_CORE_EXPORT QMutex
{
public:
#if defined(Q_COMPILER_CONSTEXPR)
    constexpr QMutex() = default;
#else
    QMutex() { d_ptr.storeRelaxed(nullptr); }
#endif
    enum RecursionMode { NonRecursive, Recursive };
    explicit QMutex(RecursionMode mode);
    ~QMutex();

    // BasicLockable concept
    void lock() QT_MUTEX_LOCK_NOEXCEPT;
    bool tryLock(int timeout = 0) QT_MUTEX_LOCK_NOEXCEPT;
    // BasicLockable concept
    void unlock() noexcept;

    // Lockable concept
    bool try_lock() QT_MUTEX_LOCK_NOEXCEPT { return tryLock(); }

#if __has_include(<chrono>) || defined(Q_CLANG_QDOC)
    // TimedLockable concept
    template <class Rep, class Period>
    bool try_lock_for(std::chrono::duration<Rep, Period> duration)
    {
        return tryLock(convertToMilliseconds(duration));
    }

    // TimedLockable concept
    template<class Clock, class Duration>
    bool try_lock_until(std::chrono::time_point<Clock, Duration> timePoint)
    {
        // Implemented in terms of try_lock_for to honor the similar
        // requirement in N4606 ¡ì 30.4.1.3 [thread.timedmutex.requirements]/12.

        return try_lock_for(timePoint - Clock::now());
    }
#endif

    bool isRecursive() const noexcept
    {
        return QBasicMutex::isRecursive();
    }

private:
    Q_DISABLE_COPY(QMutex)
        friend class QMutexLocker;
    friend class QRecursiveMutex;
    friend class ::tst_QMutex;

#if __has_include(<chrono>)
    template<class Rep, class Period>
    static int convertToMilliseconds(std::chrono::duration<Rep, Period> duration)
    {
        // N4606 ¡ì 30.4.1.3.5 [thread.timedmutex.requirements] specifies that a
        // duration less than or equal to duration.zero() shall result in a
        // try_lock, unlike QMutex's tryLock with a negative duration which
        // results in a lock.

        if (duration <= duration.zero())
            return 0;

        // when converting from 'duration' to milliseconds, make sure that
        // the result is not shorter than 'duration':
        std::chrono::milliseconds wait = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
        if (wait < duration)
            wait += std::chrono::milliseconds(1);
        Q_ASSERT(wait >= duration);
        const auto ms = wait.count();
        const auto maxInt = (std::numeric_limits<int>::max)();

        return ms < maxInt ? int(ms) : maxInt;
    }
#endif
};
