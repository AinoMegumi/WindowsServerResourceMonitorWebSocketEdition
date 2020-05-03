#pragma once
#include <Windows.h>
#include <tchar.h>

namespace ServiceInfo {
	constexpr TCHAR* Name = _T("ResMonWebSockSrvSvc");
	constexpr TCHAR* DisplayName = _T("Windows Resource Monitor Server Web Socket Edition");
	constexpr TCHAR* Description = _T("Get computer resource with running Windows Server");
	constexpr DWORD StartType = SERVICE_AUTO_START;
	constexpr bool DelayedStart = true;
	// LocalSystem    : NULL
	// LocalService   : NT AUTHORITY\\LocalService
	// NetworkService : NT AUTHORITY\\NetworkService
	constexpr const TCHAR* ExecutionUser = TEXT("NT AUTHORITY\\LocalService");
	constexpr bool RequireAdministrator = true;
}