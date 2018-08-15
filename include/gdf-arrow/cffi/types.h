
typedef size_t gdf_arrow_size_type;
typedef gdf_arrow_size_type gdf_arrow_index_type;
typedef unsigned char gdf_arrow_valid_type;

typedef enum {
    GDF_ARROW_invalid=0,
    GDF_ARROW_INT8,
    GDF_ARROW_INT16,
    GDF_ARROW_INT32,
    GDF_ARROW_INT64,
    GDF_ARROW_FLOAT32,
    GDF_ARROW_FLOAT64,
    GDF_ARROW_DATE32,   // int32_t days since the UNIX epoch
    GDF_ARROW_DATE64,   // int64_t milliseconds since the UNIX epoch
    GDF_ARROW_TIMESTAMP,// Exact timestamp encoded with int64 since UNIX epoch (Default unit millisecond)
    N_GDF_ARROW_TYPES, /* additional types should go BEFORE N_GDF_ARROW_TYPES */
} gdf_arrow_dtype;


/*
 * GDF_ARROW error enum type.
 * Any changes here should be reflected in `gdf_arrow_error_get_name` as well.
 */
typedef enum {
    GDF_ARROW_SUCCESS=0,
    GDF_ARROW_CUDA_ERROR,
    GDF_ARROW_UNSUPPORTED_DTYPE,
    GDF_ARROW_COLUMN_SIZE_MISMATCH,
    GDF_ARROW_COLUMN_SIZE_TOO_BIG,
    GDF_ARROW_DATASET_EMPTY,
    GDF_ARROW_VALIDITY_MISSING,
    GDF_ARROW_VALIDITY_UNSUPPORTED,
    GDF_ARROW_INVALID_API_CALL,
    GDF_ARROW_JOIN_DTYPE_MISMATCH,
    GDF_ARROW_JOIN_TOO_MANY_COLUMNS,
    GDF_ARROW_UNSUPPORTED_METHOD,
} gdf_arrow_error;

typedef enum {
    GDF_ARROW_HASH_MURMUR3=0,
} gdf_arrow_hash_func;

typedef enum {
	TIME_UNIT_NONE=0, // default (undefined)
	TIME_UNIT_s,   // second
	TIME_UNIT_ms,  // millisecond
	TIME_UNIT_us,  // microsecond
	TIME_UNIT_ns   // nanosecond
} gdf_arrow_time_unit;

typedef struct {
	gdf_arrow_time_unit time_unit;
	// here we can also hold info for decimal datatype or any other datatype that requires additional information
} gdf_arrow_dtype_extra_info;

typedef struct gdf_arrow_column_{
    void *data;
    gdf_arrow_valid_type *valid;
    gdf_arrow_size_type size;
    gdf_arrow_dtype dtype;
    gdf_arrow_size_type null_count;
    gdf_arrow_dtype_extra_info dtype_info;
} gdf_arrow_column;

typedef enum {
  GDF_ARROW_SORT = 0,
  GDF_ARROW_HASH,
  N_GDF_ARROW_METHODS,  /* additional methods should go BEFORE N_GDF_ARROW_METHODS */
} gdf_arrow_method;

typedef enum {
  GDF_ARROW_SUM = 0,
  GDF_ARROW_MIN,
  GDF_ARROW_MAX,
  GDF_ARROW_AVG,
  GDF_ARROW_COUNT,
  GDF_ARROW_COUNT_DISTINCT,
  N_GDF_ARROW_AGG_OPS, /* additional aggregation ops should go BEFORE N_GDF_ARROW_... */
} gdf_arrow_agg_op;

/* additonal flags */
typedef struct gdf_arrow_context_{
  int flag_sorted;        /* 0 = No, 1 = yes */
  gdf_arrow_method flag_method; /* what method is used */
  int flag_distinct;      /* for COUNT: DISTINCT = 1, else = 0 */
} gdf_arrow_context;

struct _OpaqueIpcParser;
typedef struct _OpaqueIpcParser gdf_arrow_ipc_parser_type;


struct _OpaqueRadixsortPlan;
typedef struct _OpaqueRadixsortPlan gdf_arrow_radixsort_plan_type;


struct _OpaqueSegmentedRadixsortPlan;
typedef struct _OpaqueSegmentedRadixsortPlan gdf_arrow_segmented_radixsort_plan_type;


struct _OpaqueJoinResult;
typedef struct _OpaqueJoinResult gdf_arrow_join_result_type;


typedef enum{
	GDF_ARROW_ORDER_ASC,
	GDF_ARROW_ORDER_DESC
} order_by_type;

typedef enum{
	GDF_ARROW_EQUALS,
	GDF_ARROW_NOT_EQUALS,
	GDF_ARROW_LESS_THAN,
	GDF_ARROW_LESS_THAN_OR_EQUALS,
	GDF_ARROW_GREATER_THAN,
	GDF_ARROW_GREATER_THAN_OR_EQUALS
} gdf_arrow_comparison_operator;

typedef enum{
	GDF_ARROW_WINDOW_RANGE,
	GDF_ARROW_WINDOW_ROW
} window_function_type;

typedef enum{
	GDF_ARROW_WINDOW_AVG,
	GDF_ARROW_WINDOW_SUM,
	GDF_ARROW_WINDOW_MAX,
	GDF_ARROW_WINDOW_MIN,
	GDF_ARROW_WINDOW_COUNT,
	GDF_ARROW_WINDOW_STDDEV,
	GDF_ARROW_WINDOW_VAR //variance
} window_reduction_type;
