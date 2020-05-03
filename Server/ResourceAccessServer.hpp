#pragma once
#include "httplib.h"
#include "ComInitManager.hpp"
#include "ServiceMainProcess.h"
#include "ServiceMonitor.hpp"
#include "Processor.hpp"
#include "Memory.hpp"
#include "Disk.hpp"
#include "Network.hpp"
#include "ConfigLoader.hpp"

class ResourceAccessServer : public ServiceProcess {
private:
	ComInitManager commgr;
	ConfigLoader conf;
	ServiceControlManager SCM;
	PDHQuery query;
	Processor processor;
	Memory memory;
	std::vector<Disk> disk;
	std::vector<Network> network;
	std::vector<ServiceMonitor> services;
	httplib::Server server;
	DWORD looptime;
	using BaseClass = ServiceProcess;
	std::string GetConfStr(const std::string& Section, const std::string& Key, const std::string& Default);
	std::wstring GetConfStr(const std::wstring& Section, const std::wstring& Key, const std::wstring& Default);
	int GetConfInt(const std::string& Section, const std::string& Key, const int& Default);
	picojson::object AllResourceToObject() const;
	picojson::object AllDiskResourceToObject() const;
	picojson::object AllNetworkResourceToObject() const;
	picojson::object AllServiceToObject() const;
	void UpdateResources();
	void GetDiskResourceInformations();
	void GetNetworkResourceInformations();
	void GetServiceInformations();
public:
	ResourceAccessServer(const Service_CommandLineManager::CommandLineType& args);
	void Service_MainProcess() override;
};
