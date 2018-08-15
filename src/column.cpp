#include <gdf-arrow/gdf-arrow.h>


gdf_arrow_size_type gdf_arrow_column_sizeof() {
	return sizeof(gdf_arrow_column);
}

gdf_arrow_error gdf_arrow_column_view(gdf_arrow_column *column, void *data, gdf_arrow_valid_type *valid,
				      gdf_arrow_size_type size, gdf_arrow_dtype dtype) {
	column->data = data;
	column->valid = valid;
	column->size = size;
	column->dtype = dtype;
	column->null_count = 0;
	return GDF_ARROW_SUCCESS;
}


gdf_arrow_error gdf_arrow_column_view_augmented(gdf_arrow_column *column, void *data, gdf_arrow_valid_type *valid,
						gdf_arrow_size_type size, gdf_arrow_dtype dtype, gdf_arrow_size_type null_count) {
	column->data = data;
	column->valid = valid;
	column->size = size;
	column->dtype = dtype;
	column->null_count = null_count;
	return GDF_ARROW_SUCCESS;
}


gdf_arrow_error get_column_byte_width(gdf_arrow_column * col, int * width){
	
	switch(col->dtype) {

	case GDF_ARROW_INT8 :
		*width = 1;
		break;
	case GDF_ARROW_INT16 :
		*width = 2;
		break;
	case GDF_ARROW_INT32 :
		*width = 4;
		break;
	case GDF_ARROW_INT64 :
		*width = 8;
		break;
	case GDF_ARROW_FLOAT32 :
		*width = 4;
		break;
	case GDF_ARROW_FLOAT64 :
		*width = 8;
		break;
	case GDF_ARROW_DATE32 :
		*width = 4;
		break;
	case GDF_ARROW_DATE64 :
		*width = 8;
		break;
	default :
		*width = -1;
		return GDF_ARROW_UNSUPPORTED_DTYPE;
	}

	return GDF_ARROW_SUCCESS;
}
