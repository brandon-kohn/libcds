// Copyright (c) 2006-2018 Maxim Khizhinsky
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef CDSLIB_OS_POSIX_THREAD_H
#define CDSLIB_OS_POSIX_THREAD_H

#include <pthread.h>
#include <signal.h>
#include <limits>
#include <cstdint>

namespace cds { namespace OS {
    /// posix-related wrappers
    inline namespace posix {

        /// Posix thread id type
        typedef std::thread::native_handle_type ThreadId;

        /// Get current thread id
        static inline ThreadId get_current_thread_id()
        {
            return pthread_self();
        }
        /// Get current thread id as an integral type.
        static inline std::uint64_t get_current_integral_thread_id()
        {
            auto tid = pthread_self();
            std::uint64_t rtid;
            auto r = pthread_threadid_np(tid, &rtid);
            if(!r)
                return rtid;
            return (std::numeric_limits<std::uint64_t>::max)();
        }
    }    // namespace posix

    //@cond
    constexpr const posix::ThreadId c_NullThreadId = 0;
    //@endcond

}} // namespace cds::OS


#endif // #ifndef CDSLIB_OS_POSIX_THREAD_H
