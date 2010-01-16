/* LibMemcached
 * Copyright (C) 2010 Brian Aker
 * All rights reserved.
 *
 * Use and distribution licensed under the BSD license.  See
 * the COPYING file in the parent directory for full text.
 *
 * Summary: work with user defined memory allocators
 *
 */

#ifndef __MEMCACHED_ALLOCATORS_H__
#define __MEMCACHED_ALLOCATORS_H__

#ifdef __cplusplus
extern "C" {
#endif

LIBMEMCACHED_API
memcached_return_t memcached_set_memory_allocators(memcached_st *ptr,
                                                   memcached_malloc_fn mem_malloc,
                                                   memcached_free_fn mem_free,
                                                   memcached_realloc_fn mem_realloc,
                                                   memcached_calloc_fn mem_calloc);

LIBMEMCACHED_API
void memcached_get_memory_allocators(const memcached_st *ptr,
                                     memcached_malloc_fn *mem_malloc,
                                     memcached_free_fn *mem_free,
                                     memcached_realloc_fn *mem_realloc,
                                     memcached_calloc_fn *mem_calloc);

LIBMEMCACHED_LOCAL
void libmemcached_free(const memcached_st *ptr, void *mem);

LIBMEMCACHED_LOCAL
void *libmemcached_malloc(const memcached_st *ptr, const size_t size);

LIBMEMCACHED_LOCAL
void *libmemcached_realloc(const memcached_st *ptr, void *mem, const size_t size);

LIBMEMCACHED_LOCAL
void *libmemcached_calloc(const memcached_st *ptr, size_t nelem, size_t size);


#ifdef __cplusplus
}
#endif

#endif /* __MEMCACHED_ALLOCATORS_H__ */
