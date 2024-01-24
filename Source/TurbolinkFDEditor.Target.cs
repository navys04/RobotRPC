// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TurbolinkFDEditorTarget : TargetRules
{
	public TurbolinkFDEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
#if UE_5_0_OR_LATER
        DefaultBuildSettings = BuildSettingsVersion.Latest;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
#else
        DefaultBuildSettings = BuildSettingsVersion.V2;
#endif
        ExtraModuleNames.AddRange( new string[] { "TurbolinkFD" } );
	}
}
