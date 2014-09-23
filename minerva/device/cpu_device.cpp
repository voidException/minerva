#include "cpu_device.h"

namespace minerva {

CpuDevice::CpuDevice() : Device() {}

CpuDevice::CpuDevice(uint64_t id, DeviceInfo info) : Device(id, info) {}

void CpuDevice::CreateData(uint64_t data_id, int size) {
  //DataStore& data_store_ = MinervaSystem::Instance().data_store();
  data_store_->CreateData(data_id, DataStore::CPU, size, 1);
}

float* CpuDevice::GetData(uint64_t data_id) {
  //DataStore& data_store_ = MinervaSystem::Instance().data_store();
  return data_store_->GetData(data_id, DataStore::CPU);
}

void CpuDevice::Execute_Op(std::vector<DataShard> inputShards, std::vector<DataShard> outputShards, PhysicalOp Op) {
  Context cxt;
  cxt.impl_type = Op.impl_type;
  Op.compute_fn->Execute(inputShards, outputShards, cxt);
}

}
