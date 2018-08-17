# TASK: Restructure libgdf-arrow to become more arrow alike

This is temporary document created to implement the given task.

## Current state

### libgdf-arrow

Currently, libgdf-arrow has the following file structure:
```
libgdf-arrow/
  include/
    gdf-arrow/
      gdf-arrow.h
      utils.h
      errorutils.h
      cffi/
        functions.h
	types.h
	  gdf_arrow_column {
	    void *data;
	    gdf_arrow_valid_type *valid;
            gdf_arrow_size_type size;
            gdf_arrow_dtype dtype;
            gdf_arrow_size_type null_count;
            gdf_arrow_dtype_extra_info dtype_info;
          }
	  ...
      ipc/
        api.h
	File_generated.h
	Message_generated.h
	Schema_generated.h
	Tensor_generated.h
  src/
    column.cpp
      gdf_arrow_column_sizeof()
      gdf_arrow_column_view(...)
      gdf_arrow_column_view_augmented(...)
      get_column_byte_width(...)      
    cudautils.cu
      gdf_arrow_cuda_last_error(...)
      gdf_arrow_cuda_error_string(...)
      gdf_arrow_cuda_error_name(...)
    errorhandling.cpp
      gdf_arrow_error_get_name(...)
    ipc.cu
      class IpcParser
        ...
	open(...)
	open_recordbatches(...)
	is_failed()
	get_error()
	get_data()
	get_data_offset()
	get_layout_json()
	get_schema_json()
	jsonify_node(...)
	jsonify_dtype(...)
	jsonify_buffer(...)
	read_schema(...)
	parse_schema(...)
	parse_record_batch(...)
	read_bytes(...)
	read_value(...)
	read_msg_size(...)
      cffi_wrap(...)
      cffi_unwrap(...)
      gdf_arrow_ipc_parser_open(...)
      gdf_arrow_ipc_parser_close(...)
      gdf_arrow_ipc_parser_failed(...)
      gdf_arrow_ipc_parser_get_schema_json(...)
      gdf_arrow_ipc_parser_get_layout_json(...)
      gdf_arrow_ipc_parser_get_error(...)
      gdf_arrow_ipc_parser_get_data(...)
      gdf_arrow_ipc_parser_get_data_offset(...)
      gdf_arrow_ipc_parser_open_recordbatches(...)
    tests/
      join/ - should be removed
  python/
    setup.py - builds 
    libgdf_arrow_cffi/
      __init__.py
        GDFARROWError
	libgdf_arrow - _libgdf_arrow_wrapper instance
	ffi - _cffi_backend.FFI instance
      libgdf_arrow_build.py - generator
      libgdf_arrow_cffi.py - generated, defines ffi
      wrapper.py
        _libgdf_arrow_wrapper - implementation
    tests/
      conftest.py
        rand_seed
      utils.py
        new_column()
	unwrap_devary(devary)
	get_dtype(dtype)
        seed_rand()
	gen_rand(dtype, size, **kwargs)
	fix_zeros(arr, val=1)
	buffer_as_bits(data)
      test_ipc.py
        test_arrow_availability()
	test_ipc()
  thirdparty/
    cub/
    moderngpu/
    
```

### Apache Arrow

arrow has the following file structure:
```
arrow/
  cpp/
    src/
      arrow/
        api.h
	...
        adapters/
	  ...
	compute/
	  ...
	gpu/
	  ...
	io/
	  ...
	ipc/
	  ...
	python/
	  ...
	util/
	  ...
      plasma/
        ...
    thirdparty/
      hadoop/
      jemalloc/
  ...
```

### pygdf

libgdf is used in the following parts of the pygdf:
```
pygdf/
  _gdf.py
    _columnview
      libgdf.gdf_column_view
    columnview_from_devary
      _columnview
    columnview
      _columnview
    apply_mask_and
      libgdf.gdf_validity_and
    np_to_gdf_dtype
      libgdf.GDF_FLOAT64, etc
    apply_reduce
      libgdf.gdf_reduce_optimal_output_size
    apply_prefixsum
      libgdf.gdf_prefixsum_generic
    apply_binaryop, apply_unaryop, apply_mask_and, apply_reduce, apply_sort, apply_join, SegmentedRadixortPlan.sort, hash_columns
      .cffi_view
    ...
  column.py
    class Column(object)
      .cffi_view
        _gdf.columnview
  libgdf_groupby.py
    LibGdfGroupby._apply_agg
      .cffi_view
  cudautils.py
    prefixsum
      _gdf.columnview_from_devary
      _gdf.apply_prefixsum
    mask_assign_slot
      prefixsum
    find_segments
      prefixsum
  gpuarrow.py
    class GpuArrowReader(Sequence)
      __init__, __len__, __getitem__, to_dict
      _open
        _parse_metdata
      _parse_metdata
        ffi.string, ffi.cast
        libgdf.gdf_ipc_parser_open
        libgdf.gdf_ipc_parser_close
	libgdf.gdf_ipc_parser_get_error
	libgdf.gdf_ipc_parser_open_recordbatches
	libgdf.gdf_ipc_parser_get_schema_json
	libgdf.gdf_ipc_parser_get_layout_json
	libgdf.gdf_ipc_parser_get_data_offset
```