// utilities for replacement

#ifndef _OMPTARGET_REPL_H
#define _OMPTARGET_REPL_H

#include <list>
#include <cstdint>

// GPU memory mode
extern int GMode;
// Whether to recycle GPU memory
extern int RecycleMem;
// Whether to enable partial mapping
extern bool PartialMap;
// Available device memory size
extern int64_t total_dev_size;
// Global time stamp
extern uint64_t GlobalTimeStamp;

struct HostDataToTargetTy;
struct DeviceTy;

/// Data object cluster
enum data_cluster_type {
  CLUSTER_MAPTYPE_DEV = 0,
  CLUSTER_MAPTYPE_MIX,
  CLUSTER_MAPTYPE_HST
};

struct DataClusterTy {
  void *BasePtr;
  std::list<HostDataToTargetTy*> Members;
  data_cluster_type Type = CLUSTER_MAPTYPE_MIX;
  uint64_t Size = 0;
  double Priority = 0.0;

  DataClusterTy(void *Base) : BasePtr(Base) {}
};

typedef std::list<DataClusterTy> DataClusterListTy;

/// Data attributes for each data reference used in an OpenMP target region.
enum mem_map_type {
  MEM_MAPTYPE_DEV = 0,
  MEM_MAPTYPE_SDEV,
  MEM_MAPTYPE_UVM,
  MEM_MAPTYPE_PART,
  MEM_MAPTYPE_HOST,
  MEM_MAPTYPE_UNDECIDE
};

std::pair<int64_t *, int64_t *>
target_uvm_data_mapping_opt(DeviceTy &Device, void **args_base, void **args,
                            int32_t arg_num, int64_t *arg_sizes,
                            int64_t *arg_types, void *host_ptr);

#endif
