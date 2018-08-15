from setuptools import setup

setup(name='libgdf_arrow_cffi',
      version="0.1.0a1",
      packages=["libgdf_arrow_cffi"],
      setup_requires=["cffi>=1.0.0"],
      cffi_modules=["libgdf_arrow_cffi/libgdf_arrow_build.py:ffibuilder"],
      install_requires=["cffi>=1.0.0"],
      )


