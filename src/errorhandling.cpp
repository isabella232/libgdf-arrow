#include <gdf-arrow/gdf-arrow.h>

#define GETNAME(x) case x: return #x;

const char * gdf_arrow_error_get_name(gdf_arrow_error errcode) {
    switch (errcode) {
    // There must be one entry per enum values in gdf_arrow_error.
    GETNAME(GDF_ARROW_SUCCESS)
    GETNAME(GDF_ARROW_CUDA_ERROR)
    GETNAME(GDF_ARROW_UNSUPPORTED_DTYPE)
    GETNAME(GDF_ARROW_COLUMN_SIZE_MISMATCH)
    GETNAME(GDF_ARROW_COLUMN_SIZE_TOO_BIG)
    GETNAME(GDF_ARROW_VALIDITY_MISSING)
    GETNAME(GDF_ARROW_VALIDITY_UNSUPPORTED)
    GETNAME(GDF_ARROW_JOIN_DTYPE_MISMATCH)
    GETNAME(GDF_ARROW_JOIN_TOO_MANY_COLUMNS)
    default:
        // This means we are missing an entry above for a gdf_arrow_error value.
        return "Internal error. Unknown error code.";
    }
}
