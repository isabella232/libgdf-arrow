#pragma once

/* column operations */

gdf_arrow_size_type gdf_arrow_column_sizeof();

gdf_arrow_error gdf_arrow_column_view(gdf_arrow_column *column, void *data, gdf_arrow_valid_type *valid,
				      gdf_arrow_size_type size, gdf_arrow_dtype dtype);

gdf_arrow_error gdf_arrow_column_view_augmented(gdf_arrow_column *column, void *data, gdf_arrow_valid_type *valid,
						gdf_arrow_size_type size, gdf_arrow_dtype dtype, gdf_arrow_size_type null_count);
/* error handling */

const char * gdf_arrow_error_get_name(gdf_arrow_error errcode);

int gdf_arrow_cuda_last_error();
const char * gdf_arrow_cuda_error_string(int cuda_error);
const char * gdf_arrow_cuda_error_name(int cuda_error);

/* ipc */

gdf_arrow_ipc_parser_type* gdf_arrow_ipc_parser_open(const uint8_t *schema, size_t length);
void gdf_arrow_ipc_parser_open_recordbatches(gdf_arrow_ipc_parser_type *handle,
					     const uint8_t *recordbatches,
					     size_t length);

void gdf_arrow_ipc_parser_close(gdf_arrow_ipc_parser_type *handle);
int gdf_arrow_ipc_parser_failed(gdf_arrow_ipc_parser_type *handle);
const char* gdf_arrow_ipc_parser_to_json(gdf_arrow_ipc_parser_type *handle);
const char* gdf_arrow_ipc_parser_get_error(gdf_arrow_ipc_parser_type *handle);
const void* gdf_arrow_ipc_parser_get_data(gdf_arrow_ipc_parser_type *handle);
int64_t gdf_arrow_ipc_parser_get_data_offset(gdf_arrow_ipc_parser_type *handle);

const char *gdf_arrow_ipc_parser_get_schema_json(gdf_arrow_ipc_parser_type *handle) ;
const char *gdf_arrow_ipc_parser_get_layout_json(gdf_arrow_ipc_parser_type *handle) ;

/*
 * gdf_arrow introspection utlities
 */

gdf_arrow_error get_column_byte_width(gdf_arrow_column * col, int * width);
