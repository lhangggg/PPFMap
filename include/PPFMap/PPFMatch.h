#ifndef PPFMAP_PPFMATCH_HH__
#define PPFMAP_PPFMATCH_HH__

#include <pcl/common/common_headers.h>

#include <PPFMap/Map.h>
#include <PPFMap/ppf_cuda_calls.h>

namespace ppfmap {

template <typename PointT, typename NormalT>
class PPFMatch {
public:
    typedef typename pcl::PointCloud<PointT>::Ptr PointCloudPtr;
    typedef typename pcl::PointCloud<NormalT>::Ptr NormalsPtr;

    PPFMatch(const float disc_dist, const float disc_angle)
        : discretization_distance(disc_dist)
        , discretization_angle(disc_angle) {}

    virtual ~PPFMatch() {}

    void setModelPointCloud(const PointCloudPtr model) {
        model_ = model; 
    }

    void setModelNormals(const NormalsPtr normals) {
        normals_ = normals;
    }

    void initPPFSearchStruct();

private:

    const float discretization_distance;
    const float discretization_angle;

    PointCloudPtr model_;
    NormalsPtr normals_;

    ppfmap::Map::Ptr model_ppf_map;
};

} // namespace ppfmap

#include <PPFMap/impl/PPFMatch.hpp>

#endif // PPFMAP_PPFMATCH_HH__