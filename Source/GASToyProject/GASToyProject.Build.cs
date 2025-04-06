// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GASToyProject : ModuleRules
{
	public GASToyProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks"
		
		});

        PublicIncludePaths.AddRange(new string[]
        {
            "GASToyProject/AbilitySystem/Public",
            "GASToyProject/Character/Public",
            "GASToyProject/Enemy/Public",
        });
    }
}
