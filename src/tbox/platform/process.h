/*!The Treasure Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2015, ruki All rights reserved.
 *
 * @author      ruki
 * @file        process.h
 * @ingroup     platform
 *
 */
#ifndef TB_PLATFORM_PROCESS_H
#define TB_PLATFORM_PROCESS_H

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_enter__

/* //////////////////////////////////////////////////////////////////////////////////////
 * types
 */

/// the process ref type
typedef struct{}*       tb_process_ref_t;

/* //////////////////////////////////////////////////////////////////////////////////////
 * interfaces
 */

/*! run a given process 
 *
 * @code
 
    // init argv
    tb_char_t const* argv[] = 
    {
        "echo"
    ,   "hello"
    ,   tb_null
    };
 
    // init envp
    tb_char_t const* envp[] = 
    {
        "path=/usr/bin"
    ,   tb_null
    };
    
    // run bash
    if (tb_process_run("echo", argv, envp) == 0)
    {
        // trace
        tb_trace_i("ok");
    }
 
    // run bash
    if (tb_process_run("/bin/echo", tb_null, tb_null) == 0)
    {
        // trace
        tb_trace_i("ok");
    }

 * @endcode
 * 
 * @param pathname      the process path or name
 * @param argv          the list of arguments must be terminated by a null pointer
 *                      and must be terminated by a null pointer
 *                      and argv[0] is the self path name
 * @param envp          the envp argument is an array of pointers to null-terminated strings
 *                      and must be terminated by a null pointer
 *
 * @return              the status value, failed: -1, ok: 0, other: error code
 */
tb_long_t               tb_process_run(tb_char_t const* pathname, tb_char_t* const argv[], tb_char_t* const envp[]);

/*! init a given process 
 * 
 * @code
 
    // init process
    tb_process_ref_t process = tb_process_init("/bin/echo", tb_null, tb_null, tb_false);
    if (process)
    {
        // wait process
        tb_long_t status = 0;
        if (tb_process_wait(process, &status, 10) > 0)
        {
            // trace
            tb_trace_i("process exited: %ld", status);
        }
        // kill process
        else 
        {
            // kill it
            tb_process_kill(process);

            // wait it again
            tb_process_wait(process, &status, -1);
        }

        // exit process
        tb_process_exit(process);
    }

 * @endcode
 *
 * @param pathname      the process path or name
 * @param argv          the list of arguments must be terminated by a null pointer
 *                      and must be terminated by a null pointer
 *                      and argv[0] is the self path name
 * @param envp          the envp argument is an array of pointers to null-terminated strings
 *                      and must be terminated by a null pointer
 * @param suspend       is suspended?
 *
 * @return              the process 
 */
tb_process_ref_t        tb_process_init(tb_char_t const* pathname, tb_char_t* const argv[], tb_char_t* const envp[], tb_bool_t suspend);

/*! exit the process
 *
 * @param process       the process
 */
tb_void_t               tb_process_exit(tb_process_ref_t process);

/*! kill the process
 *
 * @param process       the process
 */
tb_void_t               tb_process_kill(tb_process_ref_t process);

/*! resume the process
 *
 * @param process       the process
 */
tb_void_t               tb_process_resume(tb_process_ref_t process);

/*! suspend the process
 *
 * @param process       the process
 */
tb_void_t               tb_process_suspend(tb_process_ref_t process);

/*! wait the process
 *
 * @param process       the process
 * @param pstatus       the process exited status pointer, maybe null
 * @param timeout       the timeout (ms), infinity: -1
 *
 * @return              wait failed: -1, timeout: 0, ok: 1
 */
tb_long_t               tb_process_wait(tb_process_ref_t process, tb_long_t* pstatus, tb_long_t timeout);

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_leave__

#endif
