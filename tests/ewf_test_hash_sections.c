/*
 * Library hash_sections type test program
 *
 * Copyright (C) 2006-2017, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "ewf_test_libcerror.h"
#include "ewf_test_libewf.h"
#include "ewf_test_macros.h"
#include "ewf_test_memory.h"
#include "ewf_test_unused.h"

#include "../libewf/libewf_hash_sections.h"

#if defined( __GNUC__ )

/* Tests the libewf_hash_sections_initialize function
 * Returns 1 if successful or 0 if not
 */
int ewf_test_hash_sections_initialize(
     void )
{
	libcerror_error_t *error              = NULL;
	libewf_hash_sections_t *hash_sections = NULL;
	int result                            = 0;

#if defined( HAVE_EWF_TEST_MEMORY )
	int number_of_malloc_fail_tests       = 1;
	int number_of_memset_fail_tests       = 1;
	int test_number                       = 0;
#endif

	/* Test regular cases
	 */
	result = libewf_hash_sections_initialize(
	          &hash_sections,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        EWF_TEST_ASSERT_IS_NOT_NULL(
         "hash_sections",
         hash_sections );

        EWF_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libewf_hash_sections_free(
	          &hash_sections,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        EWF_TEST_ASSERT_IS_NULL(
         "hash_sections",
         hash_sections );

        EWF_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libewf_hash_sections_initialize(
	          NULL,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        EWF_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	hash_sections = (libewf_hash_sections_t *) 0x12345678UL;

	result = libewf_hash_sections_initialize(
	          &hash_sections,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        EWF_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	hash_sections = NULL;

#if defined( HAVE_EWF_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libewf_hash_sections_initialize with malloc failing
		 */
		ewf_test_malloc_attempts_before_fail = test_number;

		result = libewf_hash_sections_initialize(
		          &hash_sections,
		          &error );

		if( ewf_test_malloc_attempts_before_fail != -1 )
		{
			ewf_test_malloc_attempts_before_fail = -1;

			if( hash_sections != NULL )
			{
				libewf_hash_sections_free(
				 &hash_sections,
				 NULL );
			}
		}
		else
		{
			EWF_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			EWF_TEST_ASSERT_IS_NULL(
			 "hash_sections",
			 hash_sections );

			EWF_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libewf_hash_sections_initialize with memset failing
		 */
		ewf_test_memset_attempts_before_fail = test_number;

		result = libewf_hash_sections_initialize(
		          &hash_sections,
		          &error );

		if( ewf_test_memset_attempts_before_fail != -1 )
		{
			ewf_test_memset_attempts_before_fail = -1;

			if( hash_sections != NULL )
			{
				libewf_hash_sections_free(
				 &hash_sections,
				 NULL );
			}
		}
		else
		{
			EWF_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			EWF_TEST_ASSERT_IS_NULL(
			 "hash_sections",
			 hash_sections );

			EWF_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_EWF_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( hash_sections != NULL )
	{
		libewf_hash_sections_free(
		 &hash_sections,
		 NULL );
	}
	return( 0 );
}

/* Tests the libewf_hash_sections_free function
 * Returns 1 if successful or 0 if not
 */
int ewf_test_hash_sections_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libewf_hash_sections_free(
	          NULL,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        EWF_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libewf_hash_sections_clone function
 * Returns 1 if successful or 0 if not
 */
int ewf_test_hash_sections_clone(
     void )
{
	libcerror_error_t *error                          = NULL;
	libewf_hash_sections_t *destination_hash_sections = NULL;
	libewf_hash_sections_t *source_hash_sections      = NULL;
	int result                                        = 0;

	/* Initialize test
	 */
	result = libewf_hash_sections_initialize(
	          &source_hash_sections,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        EWF_TEST_ASSERT_IS_NOT_NULL(
         "source_hash_sections",
         source_hash_sections );

        EWF_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test regular cases
	 */
	result = libewf_hash_sections_clone(
	          &destination_hash_sections,
	          source_hash_sections,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        EWF_TEST_ASSERT_IS_NOT_NULL(
         "destination_hash_sections",
         destination_hash_sections );

        EWF_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libewf_hash_sections_free(
	          &destination_hash_sections,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        EWF_TEST_ASSERT_IS_NULL(
         "destination_hash_sections",
         destination_hash_sections );

        EWF_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libewf_hash_sections_clone(
	          &destination_hash_sections,
	          NULL,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        EWF_TEST_ASSERT_IS_NULL(
         "destination_hash_sections",
         destination_hash_sections );

        EWF_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libewf_hash_sections_clone(
	          NULL,
	          source_hash_sections,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        EWF_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libewf_hash_sections_free(
	          &source_hash_sections,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        EWF_TEST_ASSERT_IS_NULL(
         "source_hash_sections",
         source_hash_sections );

        EWF_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( destination_hash_sections != NULL )
	{
		libewf_hash_sections_free(
		 &destination_hash_sections,
		 NULL );
	}
	if( source_hash_sections != NULL )
	{
		libewf_hash_sections_free(
		 &source_hash_sections,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) */

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc EWF_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] EWF_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc EWF_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] EWF_TEST_ATTRIBUTE_UNUSED )
#endif
{
	EWF_TEST_UNREFERENCED_PARAMETER( argc )
	EWF_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ )

	EWF_TEST_RUN(
	 "libewf_hash_sections_initialize",
	 ewf_test_hash_sections_initialize );

	EWF_TEST_RUN(
	 "libewf_hash_sections_free",
	 ewf_test_hash_sections_free );

	EWF_TEST_RUN(
	 "libewf_hash_sections_clone",
	 ewf_test_hash_sections_clone );

	/* TODO: add tests for libewf_hash_sections_set_digest_from_hash_values */

#endif /* defined( __GNUC__ ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

