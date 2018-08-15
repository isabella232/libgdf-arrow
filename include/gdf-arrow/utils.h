#ifndef GDF_ARROW_UTILS_H
#define GDF_ARROW_UTILS_H

#include <gdf-arrow/gdf-arrow.h>

__device__
static
bool gdf_arrow_is_valid(const gdf_arrow_valid_type *valid, gdf_arrow_index_type pos) {
	if ( valid )
		return (valid[pos / GDF_ARROW_VALID_BITSIZE] >> (pos % GDF_ARROW_VALID_BITSIZE)) & 1;
	else
		return true;
}

inline gdf_arrow_size_type gdf_arrow_get_num_chars_bitmask(gdf_arrow_size_type size) {
  return (( size + ( GDF_ARROW_VALID_BITSIZE - 1)) / GDF_ARROW_VALID_BITSIZE );
}

#endif
