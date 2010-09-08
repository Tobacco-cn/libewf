/*
 * Low level reading functions
 *
 * Copyright (c) 2006-2010, Joachim Metz <jbmetz@users.sourceforge.net>
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
#include <memory.h>
#include <types.h>

#include <libcstring.h>
#include <liberror.h>

#include "libewf_single_file_entry.h"

/* Initialize the single file entry
 * Returns 1 if successful or -1 on error
 */
int libewf_single_file_entry_initialize(
     libewf_single_file_entry_t **single_file_entry,
     liberror_error_t **error )
{
	static char *function = "libewf_single_file_entry_initialize";

	if( single_file_entry == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid single file entry.",
		 function );

		return( -1 );
	}
	if( *single_file_entry == NULL )
	{
		*single_file_entry = (libewf_single_file_entry_t *) memory_allocate(
		                                                     sizeof( libewf_single_file_entry_t ) );

		if( *single_file_entry == NULL )
		{
			liberror_error_set(
			 error,
			 LIBERROR_ERROR_DOMAIN_MEMORY,
			 LIBERROR_MEMORY_ERROR_INSUFFICIENT,
			 "%s: unable to create single file entry.",
			 function );

			return( -1 );
		}
		if( memory_set(
		     *single_file_entry,
		     0,
		     sizeof( libewf_single_file_entry_t ) ) == NULL )
		{
			liberror_error_set(
			 error,
			 LIBERROR_ERROR_DOMAIN_MEMORY,
			 LIBERROR_MEMORY_ERROR_SET_FAILED,
			 "%s: unable to clear single file entry.",
			 function );

			memory_free(
			 *single_file_entry );

			*single_file_entry = NULL;

			return( -1 );
		}
	}
	return( 1 );
}

/* Frees the single file entry including elements
 * Returns 1 if successful or -1 on error
 */
int libewf_single_file_entry_free(
     intptr_t *single_file_entry,
     liberror_error_t **error )
{
	static char *function = "libewf_single_file_entry_free";

	if( single_file_entry == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid single file entry.",
		 function );

		return( 1 );
	}
	if( ( (libewf_single_file_entry_t *) single_file_entry )->name != NULL )
	{
		memory_free(
		 ( (libewf_single_file_entry_t *) single_file_entry )->name );
	}
	if( ( (libewf_single_file_entry_t *) single_file_entry )->md5_hash != NULL )
	{
		memory_free(
		 ( (libewf_single_file_entry_t *) single_file_entry )->md5_hash );
	}
	memory_free(
	 single_file_entry );

	return( 1 );
}

/* Clones the single file entry
 * Returns 1 if successful or -1 on error
 */
int libewf_single_file_entry_clone(
     intptr_t **destination_single_file_entry,
     intptr_t *source_single_file_entry,
     liberror_error_t **error )
{
	/* TODO */
	return( -1 );
}

/* Retrieves the flags
 * Returns 1 if successful or -1 on error
 */
int libewf_single_file_entry_get_flags(
     libewf_single_file_entry_t *single_file_entry,
     uint32_t *flags,
     liberror_error_t **error )
{
	static char *function = "libewf_single_file_entry_get_flags";

	if( single_file_entry == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid single file entry.",
		 function );

		return( -1 );
	}
	if( flags == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid flags.",
		 function );

		return( -1 );
	}
	*flags = single_file_entry->flags;

	return( 1 );
}

/* Retrieves the data offset
 * Returns 1 if successful or -1 on error
 */
int libewf_single_file_entry_get_data_offset(
     libewf_single_file_entry_t *single_file_entry,
     off64_t *data_offset,
     liberror_error_t **error )
{
	static char *function = "libewf_single_file_entry_get_data_offset";

	if( single_file_entry == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid single file entry.",
		 function );

		return( -1 );
	}
	if( data_offset == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid data offset.",
		 function );

		return( -1 );
	}
	*data_offset = single_file_entry->data_offset;

	return( 1 );
}

/* Retrieves the data size
 * Returns 1 if successful or -1 on error
 */
int libewf_single_file_entry_get_data_size(
     libewf_single_file_entry_t *single_file_entry,
     size64_t *data_size,
     liberror_error_t **error )
{
	static char *function = "libewf_single_file_entry_get_data_size";

	if( single_file_entry == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid single file entry.",
		 function );

		return( -1 );
	}
	if( data_size == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid data size.",
		 function );

		return( -1 );
	}
	*data_size = single_file_entry->data_size;

	return( 1 );
}

/* Retrieves the size of the UTF-8 encoded name
 * The returned size includes the end of string character
 * Returns 1 if successful or -1 on error
 */
int libewf_single_file_entry_get_utf8_name_size(
     libewf_single_file_entry_t *single_file_entry,
     size_t *utf8_name_size,
     liberror_error_t **error )
{
	static char *function = "libewf_single_file_entry_get_utf8_name_size";

	if( single_file_entry == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid single file entry.",
		 function );

		return( -1 );
	}
	if( utf8_name_size == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid UTF-8 name size.",
		 function );

		return( -1 );
	}
	*utf8_name_size = single_file_entry->name_size;

	return( 1 );
}

/* Retrieves the UTF-8 encoded name value
 * The size should include the end of string character
 * Returns 1 if successful or -1 on error
 */
int libewf_single_file_entry_get_utf8_name(
     libewf_single_file_entry_t *single_file_entry,
     uint8_t *utf8_name,
     size_t utf8_name_size,
     liberror_error_t **error )
{
	static char *function = "libewf_single_file_entry_get_utf8_name_size";

	if( single_file_entry == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid single file entry.",
		 function );

		return( -1 );
	}
	if( utf8_name == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid UTF-8 name.",
		 function );

		return( -1 );
	}
	if( utf8_name_size < single_file_entry->name_size )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
		 "%s: invalid UTF-8 name size value too small.",
		 function );

		return( -1 );
	}
	if( libcstring_narrow_string_copy(
	     (char *) utf8_name,
	     (char *) single_file_entry->name,
	     single_file_entry->name_size ) == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_MEMORY,
		 LIBERROR_MEMORY_ERROR_COPY_FAILED,
		 "%s: unable to set UTF-8 name.",
		 function );

		return( -1 );
	}
	utf8_name[ single_file_entry->name_size - 1 ] = 0;

	return( 1 );
}

/* Retrieves the size
 * Returns 1 if successful or -1 on error
 */
int libewf_single_file_entry_get_size(
     libewf_single_file_entry_t *single_file_entry,
     size64_t *size,
     liberror_error_t **error )
{
	static char *function = "libewf_single_file_entry_get_size";

	if( single_file_entry == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid single file entry.",
		 function );

		return( -1 );
	}
	if( size == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid size.",
		 function );

		return( -1 );
	}
	*size = single_file_entry->size;

	return( 1 );
}

/* Retrieves the creation date and time
 * Returns 1 if successful or -1 on error
 */
int libewf_single_file_entry_get_creation_time(
     libewf_single_file_entry_t *single_file_entry,
     uint64_t *creation_time,
     liberror_error_t **error )
{
	static char *function = "libewf_single_file_entry_get_creation_time";

	if( single_file_entry == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid single file entry.",
		 function );

		return( -1 );
	}
	if( creation_time == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid creation time.",
		 function );

		return( -1 );
	}
	*creation_time = single_file_entry->creation_time;

	return( 1 );
}

/* Retrieves the (file) modification (last written) date and time
 * Returns 1 if successful or -1 on error
 */
int libewf_single_file_entry_get_modification_time(
     libewf_single_file_entry_t *single_file_entry,
     uint64_t *modification_time,
     liberror_error_t **error )
{
	static char *function = "libewf_single_file_entry_get_modification_time";

	if( single_file_entry == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid single file entry.",
		 function );

		return( -1 );
	}
	if( modification_time == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid modification time.",
		 function );

		return( -1 );
	}
	*modification_time = single_file_entry->modification_time;

	return( 1 );
}

/* Retrieves the access date and time
 * Returns 1 if successful or -1 on error
 */
int libewf_single_file_entry_get_access_time(
     libewf_single_file_entry_t *single_file_entry,
     uint64_t *access_time,
     liberror_error_t **error )
{
	static char *function = "libewf_single_file_entry_get_access_time";

	if( single_file_entry == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid single file entry.",
		 function );

		return( -1 );
	}
	if( access_time == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid access time.",
		 function );

		return( -1 );
	}
	*access_time = single_file_entry->access_time;

	return( 1 );
}

/* Retrieves the (file system entry) modification date and time
 * Returns 1 if successful or -1 on error
 */
int libewf_single_file_entry_get_entry_modification_time(
     libewf_single_file_entry_t *single_file_entry,
     uint64_t *entry_modification_time,
     liberror_error_t **error )
{
	static char *function = "libewf_single_file_entry_get_entry_modification_time";

	if( single_file_entry == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid single file entry.",
		 function );

		return( -1 );
	}
	if( entry_modification_time == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid entry modification time.",
		 function );

		return( -1 );
	}
	*entry_modification_time = single_file_entry->entry_modification_time;

	return( 1 );
}

