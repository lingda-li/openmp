#include "replacement.h"

// GPU memory mode
int GMode = 0;
// Whether to recycle GPU memory
int RecycleMem = 0;
// Whether to enable partial mapping
bool PartialMap = false;
// Available device memory size
int64_t total_dev_size = 14 * 1024 * 1024 * 1024L;
// Global time stamp
uint64_t GlobalTimeStamp = 0;
// Partial mapped size
int64_t PartDevSize;
