// Copyright (C) Developed by Neo Jin. All Rights Reserved.
#include "TurboLinkGrpcModule.h"

#include "UObject/UObjectGlobals.h"
#include "Misc/ConfigCacheIni.h"
#include "Misc/Char.h"
#include "Logging/LogMacros.h"
#include "Logging/LogVerbosity.h"

#if PLATFORM_WINDOWS
#include "Windows/PreWindowsApi.h"
#endif

#include "grpc/grpc.h"
#include "grpc/support/log.h"
#include "google/protobuf/descriptor_database.h"

#if PLATFORM_WINDOWS
#include "Windows/PostWindowsApi.h"
#endif

#define LOCTEXT_NAMESPACE "FTurboLinkGrpcModule"

DEFINE_LOG_CATEGORY(LogTurboLink);

void GrpcLogEntry(gpr_log_func_args* args)
{
	FString logMessage = FString::Printf(TEXT("grpc:(%s:%d)%s"), UTF8_TO_TCHAR(args->file), args->line, UTF8_TO_TCHAR(args->message));

    ELogVerbosity::Type logSeverity = ELogVerbosity::Type::Log;
    switch (args->severity)
    {
    case GPR_LOG_SEVERITY_DEBUG:
		UE_LOG(LogTurboLink, Verbose, TEXT("%s"), *logMessage);
		break;
    case GPR_LOG_SEVERITY_INFO:
		UE_LOG(LogTurboLink, Log, TEXT("%s"), *logMessage);
        break;
    case GPR_LOG_SEVERITY_ERROR:
		UE_LOG(LogTurboLink, Error, TEXT("%s"), *logMessage);
        break;
    }
}

FTurboLinkGrpcModule::FTurboLinkGrpcModule()
{
}

FTurboLinkGrpcModule::~FTurboLinkGrpcModule()
{
}

void FTurboLinkGrpcModule::StartupModule()
{
	UE_LOG(LogTurboLink, Log, TEXT("Startup TurboLinkGrpcModule"));

	gpr_set_log_verbosity(GPR_LOG_SEVERITY_DEBUG);
	gpr_set_log_function(GrpcLogEntry);
}

void FTurboLinkGrpcModule::ShutdownModule()
{
	UE_LOG(LogTurboLink, Log, TEXT("Shutdown TurboLinkGrpcModule"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FTurboLinkGrpcModule, TurboLinkGrpc)
