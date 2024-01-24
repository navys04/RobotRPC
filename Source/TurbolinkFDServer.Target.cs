// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class TurbolinkFDServerTarget : TargetRules
{
	public TurbolinkFDServerTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
#if UE_5_0_OR_LATER
        DefaultBuildSettings = BuildSettingsVersion.Latest;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
#else
        DefaultBuildSettings = BuildSettingsVersion.V2;
#endif

        ExtraModuleNames.AddRange( new string[] { "TurbolinkFD" } );

		//These configurations are invalid for a Linux server build.
		DisablePlugins.Add("WMFMediaPlayer");
		DisablePlugins.Add("AsyncLoadingScreen"); //if you are using this plugin
		DisablePlugins.Add("WindowsMoviePlayer");
		DisablePlugins.Add("MediaFoundationMediaPlayer");
	}
}
