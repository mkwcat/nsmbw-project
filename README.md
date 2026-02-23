# mkwcat's nsmbw project

This is a major mod for New Super Mario Bros. Wii that adds a collection of new features to the game
alongside the base game's content. This is similar to [my gecko codes collection](../../../gecko-codes),
but for much larger changes that don't fit into a few hundred lines of text. Every feature is
consolidated into one big Riivolution pack; individual features can be disabled in the
Riivolution configuration menu.

This is still in development, so many of the specified features may not function properly. Features that
exist in some capacity include:
- Expanded player count of up to 8 players, using 4 Wii Remotes and 4 GameCube controllers.
- Death messages.
- Singleplayer Free-for-all and Coin Battle, for the lonely people out there.

And more planned for the future, once the current features are stable enough!

## How to use

[Download the latest build here](../../releases/latest/download/mkwcat-nsmbw.zip), or go to the releases
tab to see every version.

If using a real Wii, extract the ZIP file to the root of your SD Card or USB storage device, merging
the 'riivolution' folder if it already exists, and
[install Riivolution](https://oscwii.org/library/app/riivolution).

If using Dolphin, extract the ZIP file to `[Dolphin User Folder]/Load/Riivolution`. You can open the
User Folder from Dolphin via `File > Open User Folder`. After that, right click on NSMBW in the game
list and click `Start with Riivolution Patches...`.

Make sure to enable `Core (Required)` under the mkwcat section in Riivolution, as it's required for all
features to work. Please disable everything in every other section, as the mod makes plenty of changes and
is likely incompatible with any other mods you have enabled.

## Credits & Attribution

Various credits go to many wonderful people in the New Super Mario Bros. Wii community who have made and shared tools and documentation.
Most notably [Ninji](https://github.com/Treeki), [CLF78](https://github.com/CLF78),
[RoadrunnerWMC](https://github.com/RoadrunnerWMC), [RootCubed](https://github.com/RootCubed).

The following tools are included in this repository, all with some modifications:
- **[elf2rel](https://github.com/PistonMiner/ttyd-tools/tree/master/ttyd-tools/elf2rel)**; created by [Linus S. (aka PistonMiner)](https://github.com/PistonMiner), licensed under [GPLv3][gpl-3.0] or later.
- **[wuj5](https://github.com/stblr/wuj5)**; created by [Pablo Stebler](https://github.com/stblr), under the [MIT license](https://github.com/stblr/wuj5/blob/main/LICENSE).

[gpl-3.0]: https://www.gnu.org/licenses/gpl-3.0
