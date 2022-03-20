# unturned4-mod-example

The first-ever modding tutorial for Unturned II.

Note that this is not the official (made by SDG) modding tool. It was made by reverse engineering the game's code. At
this time, it's only possible to create maps and commands.

![GameAndEditor](assets/images/GameAndEditor.png)

## Prerequisites

- Unreal Engine (To find the version: Right click on the U4.exe > Properties > Details)

## Create a mod

Click the 'Create Mod' button on the toolbar. In the opened window, give your new Mod a name. Click 'Create Mod' in the
right bottom corner.

![CreateNewMod](assets/images/CreateNewMod.png)

## List your map in the game's main menu

To do so, create the Level Definition DataAsset
(see `ExampleMod/Maps/ExampleMap/LD_ExampleMap` for example). Right click on the Content Browser window >
Miscellaneous > DataAsset.

![CreateDataAsset](assets/images/CreateDataAsset.png)

Select `U4_LevelDefinition` class.

![PickLevelDefinition](assets/images/PickLevelDefinition.png)

Configure created asset.

## Create a command

1. Right click on the Content Browser window > Blueprint class.

2. Select `U4_AdminCommand` class.

   ![PickAdminCommand](assets/images/PickAdminCommand.png)

3. Add 'Execute Command' event and implement it.

   ![CommandImplementation](assets/images/CommandImplementation.png)

4. To make commands usable, you need to register them: create an instance
   of `ExampleMod/Blueprints/BP_CommandRegistrator` on your map and select what commands you want.

   ![RegisterCommands](assets/images/RegisterCommands.png)

## Package

1. Click the 'Package Mod' button on the toolbar and select which one to build.

   ![CreateCustomLaunchProfile](assets/images/PackageMod.png)

2. Copy the exported folder from `src/Mods/(your mod name)/Saved/StagedBuilds/WindowsNoEditor/U4/Mods/(your mod name)`.

3. Create a folder named `Mods` in the game's `U4` folder.

   ![CreateModsFolderInGameFiles](assets/images/CreateModsFolderInGameFiles.png)

4. Paste the `(your mod name)` folder into the game's `U4/Mods` folder.

   ![PasteModIntoModsFolder](assets/images/PasteModIntoModsFolder.png)

5. Run the game.

## Assets documentation

See [Unturned II modding docs](https://wiki.smartlydressedgames.com/wiki/Modding).

## Good luck
