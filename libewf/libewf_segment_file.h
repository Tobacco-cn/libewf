/*
 * libewf segment file
 *
 * Copyright (c) 2006-2007, Joachim Metz <forensics@hoffmannbv.nl>,
 * Hoffmann Investigations. All rights reserved.
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of the creator, related organisations, nor the names of
 *   its contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER, COMPANY AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#if !defined( _LIBEWF_SEGMENT_FILE_H )
#define _LIBEWF_SEGMENT_FILE_H

#include "libewf_includes.h"

#include <libewf/libewf_handle.h>

#include "libewf_internal_handle.h"
#include "libewf_section_list.h"

#include "ewf_crc.h"

#if defined( __cplusplus )
extern "C" {
#endif

int libewf_segment_file_check_file_signature( int file_descriptor );

ssize_t libewf_segment_file_read_file_header( int file_descriptor, uint16_t *segment_number, uint8_t *segment_file_type );

int libewf_segment_file_exists( LIBEWF_SEGMENT_TABLE *segment_table, uint16_t segment_number );

#if defined( HAVE_WIDE_CHARACTER_TYPE ) && defined( HAVE_WIDE_CHARACTER_SUPPORT_FUNCTIONS )
int libewf_segment_file_create_wide_extension( uint16_t segment_number, int16_t maximum_amount_of_segments, uint8_t segment_file_type, uint8_t ewf_format, uint8_t format, wchar_t *extension );
#else
int libewf_segment_file_create_extension( uint16_t segment_number, int16_t maximum_amount_of_segments, uint8_t segment_file_type, uint8_t ewf_format, uint8_t format, char *extension );
#endif

#if defined( HAVE_WIDE_CHARACTER_TYPE ) && defined( HAVE_WIDE_CHARACTER_SUPPORT_FUNCTIONS )
wchar_t *libewf_segment_file_create_wide_filename( uint16_t segment_number, int16_t maximum_amount_of_segments, uint8_t segment_file_type, uint8_t ewf_format, uint8_t format, wchar_t *basename );
#else
char *libewf_segment_file_create_filename( uint16_t segment_number, int16_t maximum_amount_of_segments, uint8_t segment_file_type, uint8_t ewf_format, uint8_t format, char *basename );
#endif

int libewf_segment_file_create( LIBEWF_SEGMENT_TABLE *segment_table, uint16_t segment_number, int16_t maximum_amount_of_segments, uint8_t segment_file_type, uint8_t ewf_format, uint8_t format );

int libewf_segment_file_build_segment_table( LIBEWF_INTERNAL_HANDLE *internal_handle );
int libewf_segment_file_build_delta_segment_table( LIBEWF_INTERNAL_HANDLE *internal_handle );

int libewf_segment_file_read_sections( LIBEWF_INTERNAL_HANDLE *internal_handle, uint16_t segment_number, int file_descriptor, LIBEWF_SECTION_LIST *section_list, int *last_segment_file );

ssize_t libewf_segment_file_write_headers( LIBEWF_INTERNAL_HANDLE *internal_handle, int file_descriptor, LIBEWF_SECTION_LIST *section_list, off_t start_offset );
ssize_t libewf_segment_file_write_last_section( LIBEWF_INTERNAL_HANDLE *internal_handle, int file_descriptor, LIBEWF_SECTION_LIST *section_list, off_t start_offset, int last_segment_file );

ssize_t libewf_segment_file_write_start( LIBEWF_INTERNAL_HANDLE *internal_handle, LIBEWF_SEGMENT_TABLE *segment_table, uint16_t segment_number, uint8_t segment_file_type );
ssize_t libewf_segment_file_write_end( LIBEWF_INTERNAL_HANDLE *internal_handle, int file_descriptor, LIBEWF_SECTION_LIST *section_list, off_t start_offset, int last_segment_file );

ssize_t libewf_segment_file_write_chunks_section_start( LIBEWF_INTERNAL_HANDLE *internal_handle, uint16_t segment_number, size32_t chunk_size, uint32_t total_chunk_amount, uint32_t segment_chunk_amount );

ssize_t libewf_segment_file_write_chunks_data( LIBEWF_INTERNAL_HANDLE *internal_handle, uint16_t segment_number, uint32_t chunk, EWF_CHUNK *chunk_data, size_t size, int8_t is_compressed, EWF_CRC *chunk_crc, int8_t write_crc, uint32_t amount_of_chunks );

ssize_t libewf_segment_file_write_chunks_correction( LIBEWF_INTERNAL_HANDLE *internal_handle, uint16_t segment_number, off_t chunks_section_offset, size_t chunks_section_size, uint32_t amount_of_chunks, uint32_t section_amount_of_chunks );

ssize_t libewf_segment_file_write_delta_chunk( LIBEWF_SEGMENT_TABLE *segment_table, uint16_t segment_number, uint32_t chunk, EWF_CHUNK *chunk_data, size_t chunk_size, EWF_CRC *chunk_crc );

ssize_t libewf_segment_file_write_close( LIBEWF_INTERNAL_HANDLE *internal_handle, uint16_t segment_number, uint32_t segment_amount_of_chunks, int last_segment_file );

#if defined( HAVE_WIDE_CHARACTER_TYPE ) && defined( HAVE_WIDE_CHARACTER_SUPPORT_FUNCTIONS )
int libewf_segment_file_read_wide_open( LIBEWF_INTERNAL_HANDLE *internal_handle, wchar_t * const filenames[], uint16_t file_amount, uint8_t flags );
#else
int libewf_segment_file_read_open( LIBEWF_INTERNAL_HANDLE *internal_handle, char * const filenames[], uint16_t file_amount, uint8_t flags );
#endif

/*
#if defined( HAVE_WIDE_CHARACTER_TYPE ) && defined( HAVE_WIDE_CHARACTER_SUPPORT_FUNCTIONS )
int libewf_segment_file_write_wide_open( LIBEWF_INTERNAL_HANDLE *internal_handle, wchar_t * const filenames[], uint16_t file_amount );
#else
int libewf_segment_file_write_open( LIBEWF_INTERNAL_HANDLE *internal_handle, char * const filenames[], uint16_t file_amount );
#endif
*/

off_t libewf_segment_file_seek_chunk_offset( LIBEWF_INTERNAL_HANDLE *internal_handle, uint32_t chunk );

int libewf_segment_file_close_all( LIBEWF_INTERNAL_HANDLE *internal_handle );

#if defined( __cplusplus )
}
#endif

#endif
