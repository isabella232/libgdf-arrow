set -e

echo "Building libgdf-arrow"
conda build conda-recipes/libgdf_arrow -c defaults -c conda-forge -c numba
