/*******************************************************************************

   Copyright (C) 2012-2014 SequoiaDB Ltd.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

*******************************************************************************/

#ifndef OSSFEAT_H_
#define OSSFEAT_H_

/**
 *   \file ossfeat.h
 *   \brief Operating system specific features
 *
 */

// in windows, both 32 and 64 shows _WIN32
#if defined (_WIN32)
   #define _WINDOWS
   #include <ws2tcpip.h>
   #include <Windows.h>
   #include <WinBase.h>
   #define __FUNC__ __FUNCTION__
#endif

// platform macros
// only windows 64 bit has _win64
#if defined (_WIN32) && !defined (_WIN64)
   #define _WINDOWS32
#elif defined (_WIN64)
   #define _WINDOWS64
#endif

#if defined(__linux__)  && defined(__i386__)
   #define _LIN32
   #define _LINUX
#elif defined(__linux__) && (defined(__ia64__)||defined(__x86_64__))
   #define _LIN64
   #define _LINUX
#elif defined(__linux__) && (defined(__PPC64__))
   #define _PPCLIN64
   #define _LINUX
#endif

// architecture
#if defined ( _WINDOWS32 ) || defined ( _LIN32 )
   #define OSS_ARCH_32
#elif defined ( _WINDOWS64 ) || defined ( _LIN64 ) || defined ( _PPCLIN64 )
   #define OSS_ARCH_64
#endif

#define OSS_OSTYPE_WIN32               0
#define OSS_OSTYPE_WIN64               1
#define OSS_OSTYPE_LIN32               2
#define OSS_OSTYPE_LIN64               3
#define OSS_OSTYPE_PPCLIN64            4
#if defined (_WINDOWS32)
#define OSS_OSTYPE                     OSS_OSTYPE_WIN32
#elif defined (_WINDOWS64)
#define OSS_OSTYPE                     OSS_OSTYPE_WIN64
#elif defined (_LIN32)
#define OSS_OSTYPE                     OSS_OSTYPE_LIN32
#elif defined (_LIN64)
#define OSS_OSTYPE                     OSS_OSTYPE_LIN64
#elif defined (_PPCLIN64)
#define OSS_OSTYPE                     OSS_OSTYPE_PPCLIN64
#endif


#if defined _LINUX
   #include <errno.h>
   #define OSS_HAS_KERNEL_THREAD_ID
   #define __FUNC__ __func__
   #define SDB_EXPORT

   // max fd size is 65528 on linux
   #define OSS_FD_SETSIZE  65528
   // this header must be included BEFORE __FD_SETSIZE declaration
   #include <bits/types.h>
   #include <linux/posix_types.h>

   // must not include select.h before the file
   #if defined (SDB_ENGINE) || defined (SDB_CLIENT)
      #ifdef _SYS_SELECT_H
      # error "Can't include <sys/select.h> before the file"
      #endif //_SYS_SELECT_H
   #endif //SDB_ENGINE || SDB_CLIENT

   // __FD_SETSIZE is only for Linux and HPUX
   #undef __FD_SETSIZE
   #define __FD_SETSIZE    OSS_FD_SETSIZE
   // FD_SETSIZE is for all other unix
   #undef FD_SETSIZE
   #define FD_SETSIZE      __FD_SETSIZE
   // sys/types.h must be included AFTER __FD_SETSIZE declaration
   #include <sys/types.h>

#elif defined _WINDOWS
   #ifdef SDB_STATIC_BUILD
      #define SDB_EXPORT
   #elif defined SDB_DLL_BUILD
      #define SDB_EXPORT __declspec(dllexport)
   #else
      #define SDB_EXPORT __declspec(dllimport)
   #endif
   // we can't change fd_setsize for windows
   #define OSS_FD_SETSIZE  FD_SETSIZE
   #include <sys/types.h>
#endif

#endif /* OSSFEAT_H_ */

