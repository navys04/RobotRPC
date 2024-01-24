// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TurbolinkFDTarget : TargetRules
{
	public TurbolinkFDTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
#if UE_5_0_OR_LATER
        DefaultBuildSettings = BuildSettingsVersion.Latest;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
#else
        DefaultBuildSettings = BuildSettingsVersion.V2;
#endif
        ExtraModuleNames.AddRange( new string[] { "TurbolinkFD" } );
	}
}
