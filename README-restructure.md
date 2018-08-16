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
      ipc/
        api.h
	File_generated.h
	Message_generated.h
	Schema_generated.h
	Tensor_generated.h
  src/
    column.cpp
    cudautils.cu
    errorhandling.cpp
    ipc.cu
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