#pragma once
#include <thread>
#include <cstdint>
#include <list>
#include <vector>
#include <map>
#include <set>



// #include "tools_color_printf.hpp"
// #include "tools_thread_pool.hpp"
// #include "tools_timer.hpp"
// #include "tools_logger.hpp"

// #include "value_redefine.hpp"
// #include "tools_read_parm.hpp"

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>
#include <eigen3/Eigen/StdVector>
// #include <dbg.h>


#define mersys_MOD

// #include <cereal/cereal.hpp>
// #include <cereal/types/memory.hpp>
// #include <cereal/types/utility.hpp>
// #include <cereal/types/vector.hpp>
// #include <cereal/types/polymorphic.hpp>
// #include <cereal/types/concepts/pair_associative_container.hpp>
// #include <cereal/types/base_class.hpp>
// #include <cereal/archives/binary.hpp>
// #include <cereal/archives/binary.hpp>
// #include <cereal/access.hpp>


// #include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
// #include <pcl/kdtree/kdtree_flann.h>
// #include <pcl/io/pcd_io.h>
// #include <pcl/filters/radius_outlier_removal.h>
// #include <pcl/filters/statistical_outlier_removal.h>
// #include <pcl/common/transforms.h>

// #include "opencv2/opencv.hpp"

#define MAPRANGE std::numeric_limits<uint8_t>::max()
#define KFRANGE std::numeric_limits<uint16_t>::max()
#define MPRANGE std::numeric_limits<uint32_t>::max()
#define UIDRANGE std::numeric_limits<uint32_t>::max()

#define defpair std::make_pair((size_t)KFRANGE,(size_t)MAPRANGE) //default pair
#define defid -1 //default id

#define FRAME_GRID_ROWS 48
#define FRAME_GRID_COLS 64

#define MAX_CLIENT_NUM   20\

#define POINTCLOUD_HAVE_INTENSITY 1
#define DISPLAY_POINTCLOUD_INTENSITY 1
#define USING_OPENCV_TBB 1
#define SAVE_FRAMES 1
// namespace pcl{
// // public:
//     class PointXYZI;
//     class PointXYZINormal;   
//     class PointXYZRGB;

//     template<typename T> class PointCloud; 
//     template<typename T> class VoxelGrid;
// };

namespace cv{
// public:
    class Mat;
};

namespace mersys {


// extern std::shared_ptr<Common_tools::ThreadPool> m_thread_pool_ptr;
// extern Common_tools::Cost_time_logger g_cost_time_logger;

struct IMU_Measurement;
struct Global_map;
// Forward Decs
class Communicator_server;
class Communicator_client;
class Keyframe;
class Landmark;
class Map;

class MapInstance;  
class MapManager;
class Calibration;
class PlaceRecognition;
class Visualizer;
class Client;
class PointCloud_ex;
class Image_ex;
class ServiceManager;
class Instruction;
// class pcl::PointXYZI;
// class pcl::PointXYZRGB;
// class pcl::PointCloud;


struct Global_map;
struct MsgKeyframe;
struct MsgLandmark;
struct MsgPointCloud;
struct MsgImage;
struct MsgInstruction;
// struct MsgOdometry;
struct LoopConstraint;
// Class 
// typedef pcl::PointXYZINormal PointType;

namespace TypeDefs {

    using precision_t                   = double;   // system-wide precision type
    using keypoint_precision_t          = float;    // for 2D keypoint coordinates - float to reduce network traffic
    using idpair                        = std::pair<size_t,size_t>;
    using idpairVector                        = std::vector<idpair>;
    using ThreadPtr                     = std::unique_ptr<std::thread>;

    // #define PointType_                  = pcl::PointXYZINormal;
#if POINTCLOUD_HAVE_INTENSITY
    using PointType                     = pcl::PointXYZI;
#elif
    using PointType                     = pcl::PointXYZI;
#endif
    // using PointType                     = pcl::PointXYZI;
    using PointTypeRGB                  = pcl::PointXYZRGB;
    using VoxelGrid                     = pcl::VoxelGrid<PointType>;
    using PointCloud                    = pcl::PointCloud<PointType>;// pcl::PointCloud<PointXYZINormal>
    using PointCloudRBG                 = pcl::PointCloud<PointTypeRGB>;
    using PointCloudEX                  = PointCloud_ex;
    using ImageEX                       = Image_ex;

    using CommClientPtr                 = std::shared_ptr<Communicator_client>;
    using CommServerPtr                 = std::shared_ptr<Communicator_server>;
    using KeyframePtr                   = std::shared_ptr<Keyframe>;
    using LandmarkPtr                   = std::shared_ptr<Landmark>;
    using PointCloudPtr                 = std::shared_ptr<PointCloud>;
    using PointCloudEXPtr               = std::shared_ptr<PointCloudEX>;
    using RGBMap               = Global_map ;
    using RGBMapPtr               = std::shared_ptr<Global_map> ;
    using Image                         = cv::Mat;
    using ImagePtr                      = std::shared_ptr<Image>;
    using ImageEXPtr                    = std::shared_ptr<ImageEX>;

    using ClientPtr                        = std::shared_ptr<Client>;
    using ClientVector                     = std::vector<ClientPtr>;
    using MapPtr                           = std::shared_ptr<Map>;
    using MapInstancePtr                   = std::shared_ptr<MapInstance>;
    using MapManagerPtr                    = std::shared_ptr<MapManager>;
    using ServiceManager                    = std::shared_ptr<ServiceManager>;
    using CalibrationPtr                  = std::shared_ptr<Calibration>;
    using PlacerecPtr                   = std::shared_ptr<PlaceRecognition>;

    using VisPtr                        = std::shared_ptr<Visualizer>;

    using KeypointType                  = Eigen::Matrix<keypoint_precision_t,2,1>;
    using AorsType                      = Eigen::Matrix<keypoint_precision_t,4,1>;

    using KeypointVector                = std::vector<KeypointType,Eigen::aligned_allocator<KeypointType>>;
    using AorsVector                    = std::vector<AorsType,Eigen::aligned_allocator<AorsType>>;


    using Vector2Type                   = Eigen::Matrix<precision_t,2,1>;
    using Vector3Type                   = Eigen::Matrix<precision_t,3,1>;
    using Vector4Type                   = Eigen::Matrix<precision_t,4,1>;
    using Vector6Type                   = Eigen::Matrix<precision_t,6,1>;
    using DynamicVectorType             = Eigen::Matrix<precision_t,Eigen::Dynamic,1>;
    using QuaternionType                = Eigen::Quaternion<precision_t>;

    using Matrix3Type                   = Eigen::Matrix<precision_t,3,3>;
    using Matrix4Type                   = Eigen::Matrix<precision_t,4,4>;
    using Matrix6Type                   = Eigen::Matrix<precision_t,6,6>;
    using TransformType                 = Eigen::Isometry3d;//Matrix4Type;
    using TransformTypeList             = std::list<TransformType,Eigen::aligned_allocator<TransformType>>;


    // using TransformTypeMap                 = std::map<idpair,TransformType,std::less<idpair>,Eigen::aligned_allocator<std::pair<const idpair,TransformType>>>;
    // using TransformTypeVector                 = std::vector<TransformType,Eigen::aligned_allocator<TransformType>>;

    using DynamicMatrixType             = Eigen::Matrix<precision_t,Eigen::Dynamic,Eigen::Dynamic>;

    using Vector2Vector                 = std::vector<Vector2Type,Eigen::aligned_allocator<Vector2Type>>;
    using Vector3Vector                 = std::vector<Vector3Type,Eigen::aligned_allocator<Vector3Type>>;
    using Vector4Vector                 = std::vector<Vector4Type,Eigen::aligned_allocator<Vector4Type>>;
    using Matrix3Vector                 = std::vector<Vector4Type,Eigen::aligned_allocator<Matrix3Type>>;
    using Matrix4Vector                 = std::vector<Vector4Type,Eigen::aligned_allocator<Matrix4Type>>;
    
    using TransformVector               = std::vector<Vector4Type,Eigen::aligned_allocator<TransformType>>;
    using PoseMap                       = std::map<idpair,TransformType,std::less<idpair>,Eigen::aligned_allocator<std::pair<const idpair,TransformType>>>;
    using PoseMap_single                 = std::map<size_t,TransformType,std::less<size_t>,Eigen::aligned_allocator<std::pair<const size_t,TransformType>>>;
    // using VectorIMU                     = std::vector<IMU_Measurement>;

    using KeyframeVector                = std::vector<KeyframePtr,Eigen::aligned_allocator<KeyframePtr>>;
    using LandmarkVector                = std::vector<LandmarkPtr,Eigen::aligned_allocator<LandmarkPtr>>;
    using PointCloudVector                = std::vector<PointCloudPtr,Eigen::aligned_allocator<PointCloudPtr>>;
    using PointCloudEXVector                = std::vector<PointCloudEXPtr,Eigen::aligned_allocator<PointCloudEXPtr>>;

    using ImageEXList                    = std::list<ImageEXPtr,Eigen::aligned_allocator<ImageEXPtr>>;
    using KeyframeList                  = std::list<KeyframePtr,Eigen::aligned_allocator<KeyframePtr>>;
    using LandmarkList                  = std::list<LandmarkPtr,Eigen::aligned_allocator<LandmarkPtr>>;
    using PointCloudEXList              = std::list<PointCloudEXPtr,Eigen::aligned_allocator<PointCloudEXPtr>>;
    using InstructionList             = std::list<Instruction,Eigen::aligned_allocator<Instruction>>;

    using KeyframeSet                   = std::set<KeyframePtr,std::less<KeyframePtr>,Eigen::aligned_allocator<KeyframePtr>>;
    using LandmarkSet                   = std::set<LandmarkPtr,std::less<LandmarkPtr>,Eigen::aligned_allocator<LandmarkPtr>>;
    using PointCloudEXSet                 = std::set<PointCloudEXPtr,std::less<PointCloudEXPtr>,Eigen::aligned_allocator<PointCloudEXPtr>>;

    using KeyframeMap                   = std::map<idpair,KeyframePtr,std::less<idpair>,Eigen::aligned_allocator<std::pair<const idpair,KeyframePtr>>>; // map allocator: first element of pair must be declared const
    using LandmarkMap                   = std::map<idpair,LandmarkPtr,std::less<idpair>,Eigen::aligned_allocator<std::pair<const idpair,LandmarkPtr>>>; // map allocator: first element of pair must be declared const
    using PointCloudMap                 = std::map<idpair,PointCloudPtr,std::less<idpair>,Eigen::aligned_allocator<std::pair<const idpair,PointCloudPtr>>>; // map allocator: first element of pair must be declared const
    using PointCloudEXMap               = std::map<idpair,PointCloudEXPtr,std::less<idpair>,Eigen::aligned_allocator<std::pair<const idpair,PointCloudEXPtr>>>; // map allocator: first element of pair must be declared const
    using ImageMap                      = std::map<idpair,ImagePtr,std::less<idpair>,Eigen::aligned_allocator<std::pair<const idpair,ImagePtr>>>; // map allocator: first element of pair must be declared const
    using ImageEXMap                    = std::map<idpair,ImageEXPtr,std::less<idpair>,Eigen::aligned_allocator<std::pair<const idpair,ImageEXPtr>>>; // map allocator: first element of pair must be declared const

    using MapTransform                      = std::map<size_t,TransformType,std::less<size_t>,Eigen::aligned_allocator<std::pair<const size_t,TransformType>>>;


    using KeyframePairVector            = std::vector<std::pair<KeyframePtr,KeyframePtr>, Eigen::aligned_allocator<std::pair<KeyframePtr,KeyframePtr>>>;
    using KeyframeIntMap                = std::map<KeyframePtr,int,std::less<KeyframePtr>,Eigen::aligned_allocator<std::pair<const KeyframePtr,int>>>;
    using LoopVector                    = std::vector<LoopConstraint, Eigen::aligned_allocator<LoopConstraint>>;
    using LoopConnectionType            = std::map<KeyframePtr,KeyframeSet,std::less<KeyframePtr>,Eigen::aligned_allocator<std::pair<const KeyframePtr,KeyframeSet>>>;
    using IntKfPair                     = std::pair<int,KeyframePtr>;
    using VectorIntKfPair               = std::vector<IntKfPair,Eigen::aligned_allocator<IntKfPair>>;
    using KfObservations                = std::map<KeyframePtr,size_t,std::less<KeyframePtr>,Eigen::aligned_allocator<std::pair<const KeyframePtr,size_t>>>;

    // communication-specific
    using MsgTypeVector                 = std::vector<uint32_t>;
    using LandmarksMinimalType          = std::map<int, idpair>;
    using ObservationsMinimalType       = std::map<idpair,int>;

    using KeyframeMsgList               = std::list<MsgKeyframe,Eigen::aligned_allocator<MsgKeyframe>>;
    using LandmarkMsgList               = std::list<MsgLandmark,Eigen::aligned_allocator<MsgLandmark>>;
    using PointCloudMsgList             = std::list<MsgPointCloud,Eigen::aligned_allocator<MsgPointCloud>>;
    using ImageMsgList                  = std::list<MsgImage,Eigen::aligned_allocator<MsgImage>>;
    using InstructionMsgList             = std::list<MsgInstruction,Eigen::aligned_allocator<MsgInstruction>>;
    // using OdometryMsgList               = std::list<MsgOdometry,Eigen::aligned_allocator<MsgOdometry>>;
}


// auto TransformType::less::operator ()(const PointCloudEXPtr a, const PointCloudEXPtr b) const ->bool
// {
//     if(a->GetClientID() < b->GetClientID())
//         return true;
//     else if(a->GetClientID() > b->GetClientID())
//         return false;
//     else {
//         return a->GetFrameID() < b->GetFrameID();
//     }
// }

inline std::ostream &operator<<(std::ostream &out, const TypeDefs::idpair id) {
    return out << id.first << "|" << id.second;
}

struct IMU_Measurement
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    using precision_t                   = TypeDefs::precision_t;

public:
    IMU_Measurement() = delete;
    IMU_Measurement(precision_t lax, precision_t lay, precision_t laz,
                    precision_t avx, precision_t avy, precision_t avz,
                    precision_t dt)
        : lin_acc_x(lax),
          lin_acc_y(lay),
          lin_acc_z(laz),
          ang_vel_x(avx),
          ang_vel_y(avy),
          ang_vel_z(avz),
          delta_t(dt)
    {}

    IMU_Measurement(precision_t lax, precision_t lay, precision_t laz,
                    precision_t avx, precision_t avy, precision_t avz,
                    IMU_Measurement& imu_last,
                    precision_t dt_before, precision_t dt_after)
        : delta_t(dt_before)
    {
        precision_t w1 = dt_after / (dt_before + dt_after);       //If timestamp is closer to the new message, the old message has less weight
        precision_t w2 = dt_before  / (dt_before + dt_after);
        lin_acc_x = w1 * imu_last.lin_acc_x + w2 * lax;
        lin_acc_y = w1 * imu_last.lin_acc_y + w2 * lay;
        lin_acc_z = w1 * imu_last.lin_acc_z + w2 * laz;
        ang_vel_x = w1 * imu_last.ang_vel_x + w2 * avx;
        ang_vel_y = w1 * imu_last.ang_vel_y + w2 * avy;
        ang_vel_z = w1 * imu_last.ang_vel_z + w2 * avz;
    }

    precision_t                 lin_acc_x;
    precision_t                 lin_acc_y;
    precision_t                 lin_acc_z;
    precision_t                 ang_vel_x;
    precision_t                 ang_vel_y;
    precision_t                 ang_vel_z;
    precision_t                 delta_t;
};

enum eDistortionModel
{
    NOTSET_DIST     = -1,
    RADTAN          =  0,
    EQUI            =  1,
    PLUMBBOB        =  2
};

enum eCamModel
{
    NOTSET_CAM      = -1,
    PINHOLE         =  0,
    OMNI            =  1
};

class Keyframe;
class PointCloud_ex;

// struct LoopConstraint {
//     using TransformType             = TypeDefs::TransformType;
//     using KeyframePtr               = std::shared_ptr<Keyframe>;
//     using PointCloudEX               = TypeDefs::PointCloudEX;
//     using PointCloudEXPtr               = TypeDefs::PointCloudEXPtr;
//     using Matrix6Type               = TypeDefs::Matrix6Type;
//     using idpair               = TypeDefs::idpair;
//     LoopConstraint(PointCloudEXPtr k1, PointCloudEXPtr k2, TransformType T_12,
//                    Matrix6Type covm = Matrix6Type::Identity())
//         : pc1(k1), pc2(k2), T_s1_s2(T_12), cov_mat(covm) {
//             if (pc1->GetClientID() == pc2->GetClientID()){
//                 is_same_client=true;
//             }else{
//                 is_same_client=false;
//             }
//             // pose1.first = k1->GetFrameID();
//             // pose1.second = k1->GetClientID();
//             pose1 = pc1->GetFrameClientID();

//             pose2 = pc2->GetFrameClientID();


//         }

//     // LoopConstraint(PointCloudEXPtr k1, PointCloudEXPtr k2, TransformType T_12,
//     //                Matrix6Type covm = Matrix6Type::Identity())
//     //     : pc1(k1), pc2(k2), T_s1_s2(T_12), cov_mat(covm) {}
//     uint8_t type = 0;    // 0: pc+pc, 1: pc+camera, 2: camera+camera 
//     PointCloudEXPtr         pc1;
//     PointCloudEXPtr         pc2;

//     idpair                  pose1;
//     idpair                  pose2;

//     bool                    is_same_client = false;
//     // PointCloudEXPtr         pc1;
//     // PointCloudEXPtr         pc2;

//     TransformType       T_s1_s2;
//     Matrix6Type         cov_mat;
// };

struct VICalibration {

public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    using precision_t                   = TypeDefs::precision_t;
    using Vector2Type                   = TypeDefs::Vector2Type;
    using Vector3Type                   = TypeDefs::Vector3Type;
    using Matrix3Type                   = TypeDefs::Matrix3Type;
    using TransformType                 = TypeDefs::TransformType;
    using DynamicVectorType             = TypeDefs::DynamicVectorType;

public:

    VICalibration()
        : T_SC(Eigen::Matrix4d::Zero()),cam_model(static_cast<eCamModel>(-1)),dist_model(static_cast<eDistortionModel>(-1)),
          img_dims((Eigen::Matrix<double,2,1>::Zero())),
          dist_coeffs(Eigen::Vector4d::Zero()),
          intrinsics(Eigen::Matrix<double,4,1>::Zero()),
          K((Eigen::Matrix<double,3,3>() << 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0).finished()),
          a_max(0.0),g_max(0.0),
          sigma_a_c(0.0),sigma_g_c(0.0),sigma_ba(0.0),sigma_bg(0.0),sigma_aw_c(0.0),sigma_gw_c(0.0),
          tau(0.0),g(0.0),a0(Eigen::Vector3d::Zero()),rate(0),
          delay_cam0_to_imu(0.0),delay_cam1_to_imu(0.0)
    {}

    VICalibration(Eigen::Matrix4d Tsc,eCamModel cmodel, eDistortionModel dmodel,
                  Eigen::VectorXd DistCoeffs,
                  double dw,double dh,
                  double dfx,double dfy,double dcx,double dcy,
                  double damax,double dgmax,double dsigmaac,double dsigmagc,double dsigmaba,double dsigmabg,double dsigmaawc,double dsigmagwc,
                  double dtau,double dg,Eigen::Vector3d va0,int irate,
                  double dDelayC0toIMU,double dDelayC1toIMU)
        : T_SC(Tsc),cam_model(cmodel),dist_model(dmodel),
          img_dims((Eigen::Matrix<precision_t,2,1>() << dw,dh).finished()),
          dist_coeffs(DistCoeffs),
          intrinsics((Eigen::Matrix<precision_t,4,1>() << dfx,dfy,dcx,dcy).finished()),
          K((Eigen::Matrix<precision_t,3,3>() << dfx, 0.0, dcx, 0.0, dfy, dcy, 0.0, 0.0, 1.0).finished()),
          a_max(damax),g_max(dgmax),
          sigma_a_c(dsigmaac),sigma_g_c(dsigmagc),sigma_ba(dsigmaba),sigma_bg(dsigmabg),sigma_aw_c(dsigmaawc),sigma_gw_c(dsigmagwc),
          tau(dtau),g(dg),a0(va0),rate(irate),
          delay_cam0_to_imu(dDelayC0toIMU),delay_cam1_to_imu(dDelayC1toIMU)
    {}

    //Cam
    Eigen::Matrix4d             T_SC;                                                                                           ///< Transformation from camera to sensor (IMU) frame.
    eCamModel                   cam_model;                                                                                      ///< Distortion type. ('pinhole' 'omni')
    eDistortionModel            dist_model;                                                                                     ///< Distortion type. ('radialtangential' 'plumb_bob' 'equidistant')
    Vector2Type                 img_dims;                                                                                       ///< Image dimension. [pixels] (width;height)
    DynamicVectorType           dist_coeffs;                                                                                    ///< Distortion Coefficients.
    DynamicVectorType           intrinsics;                                                                                     ///< fx fy cx cy
    Matrix3Type                 K;
    //IMU
    precision_t                 a_max;                                                                                          ///< Accelerometer saturation. [m/s^2] -- not used
    precision_t                 g_max;                                                                                          ///< Gyroscope saturation. [rad/s] -- not used
    precision_t                 sigma_a_c;                                                                                      ///< Accelerometer noise density.
    precision_t                 sigma_g_c;                                                                                      ///< Gyroscope noise density.
    precision_t                 sigma_ba;                                                                                       ///< Initial accelerometer bias -- not used
    precision_t                 sigma_bg;                                                                                       ///< Initial gyroscope bias. -- not used
    precision_t                 sigma_aw_c;                                                                                     ///< Accelerometer drift noise density.
    precision_t                 sigma_gw_c;                                                                                     ///< Gyroscope drift noise density.
    precision_t                 tau;                                                                                            ///< Reversion time constant of accerometer bias. [s] -- not used
    precision_t                 g;                                                                                              ///< Earth acceleration.
    Vector3Type                 a0;                                                                                             ///< Mean of the prior accelerometer bias. -- not used
    int                         rate;                                                                                           ///< IMU rate in Hz.
    precision_t                 delay_cam0_to_imu;                                                                              ///< Timestamp shift. Timu = Timage + image_delay
    precision_t                 delay_cam1_to_imu;                                                                              ///< Timestamp shift. Timu = Timage + image_delay

    void show()
    {
        std::cout << "--- Cam ---" << std::endl;
        std::cout << "T_SC: \n" << T_SC << std::endl;
        if(cam_model == eCamModel::PINHOLE)                 std::cout << "CamModel: pinhole" << std::endl;
        else if(cam_model == eCamModel::OMNI)               std::cout << "CamModel: omni" << std::endl;
        if(dist_model == eDistortionModel::RADTAN)          std::cout << "DistortionModel: radialtangential" << std::endl;
        else if(dist_model == eDistortionModel::EQUI)       std::cout << "DistortionModel: equidistant" << std::endl;
        else if(dist_model == eDistortionModel::PLUMBBOB)   std::cout << "DistortionModel: plumb_bob" << std::endl;
        std::cout << "Image Dimensions: \n" << img_dims << std::endl;
        std::cout << "Distortion Coefficients: \n" << dist_coeffs << std::endl;
        std::cout << "Intrinsics: \n" << intrinsics << std::endl;
        std::cout << "K: \n" << K << std::endl;
        std::cout << "--- IMU ---" << std::endl;
        std::cout << "a_max: " << a_max << std::endl;
        std::cout << "g_max: " << g_max << std::endl;
        std::cout << "sigma_g_c: " << sigma_g_c << std::endl;
        std::cout << "sigma_bg: " << sigma_bg << std::endl;
        std::cout << "sigma_a_c: " << sigma_a_c << std::endl;
        std::cout << "sigma_ba: " << sigma_ba << std::endl;
        std::cout << "sigma_gw_c: " << sigma_gw_c << std::endl;
        std::cout << "sigma_aw_c: " << sigma_aw_c << std::endl;
        std::cout << "tau: " << tau << std::endl;
        std::cout << "g: " << g << std::endl;
        std::cout << "a0: \n" << a0 << std::endl;
        std::cout << "rate: " << rate << std::endl;
        std::cout << "delay_cam0_to_imu: " << delay_cam0_to_imu << std::endl;
        std::cout << "delay_cam1_to_imu: " << delay_cam1_to_imu << std::endl;
    }

    template<class Archive> auto serialize( Archive & archive )->void {
        archive(T_SC, cam_model, dist_model, img_dims, dist_coeffs, intrinsics, K,
                a_max, g_max, sigma_a_c, sigma_g_c, sigma_ba, sigma_bg, sigma_aw_c, sigma_gw_c, tau, g, a0,
                rate, delay_cam0_to_imu, delay_cam1_to_imu);
    }
};


}