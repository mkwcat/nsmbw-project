# mkwcat's nsmbw project

This is a major mod for New Super Mario Bros. Wii that adds a collection of new features to the game
alongside the base game's content. This is similar to [my gecko codes collection](../../../gecko-codes),
but for much larger changes that don't fit into a few hundred lines of text. Every feature is
consolidated into one big Riivolution pack; individual features can be disabled in the
Riivolution configuration menu.

This is still in development, so many of the specified features may not function properly. The mod
contains the following **optional** new features:
- Expanded player count of up to 8 players, using 4 Wii Remotes and 4 GameCube controllers.
  - The Classic Controller extension can also be used as an additional controller alongside
    the connected Wii Remote. Press (+) on the Classic Controller on the character select screen
    to split the Wii Remote and the extension into two separate players.
- On-screen death messages.
- Singleplayer Free-for-all and Coin Battle, for the lonely people out there.
- Brand new Bubble Swarm mode, where players are chased by bubbles containing deadly 1-ups.
- Ability to lift literally anything, including enemies, still objects, or ground tiles.
- Quality of life options, such as disabling the brief pause that occurs when obtaining powerups.
- Uncapped fire rate of fireballs and ice balls.

And more planned for the future, once the current features are stable enough! None of the features
specified are required and can be individually toggled.

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

Various credits go to many wonderful people in the New Super Mario Bros. Wii community who have made and
shared tools and documentation.
Most notably [Ninji](https://github.com/Treeki), [CLF78](https://github.com/CLF78),
[RoadrunnerWMC](https://github.com/RoadrunnerWMC), [RootCubed](https://github.com/RootCubed),
[MandyIGuess](https://github.com/MandyIGuess), [vabold](https://github.com/vabold),
[Ryguy](https://github.com/Ryguy0777).

The following tools are included in this repository, all with some modifications:
- **[wuj5](https://github.com/stblr/wuj5)**; created by [Pablo Stebler](https://github.com/stblr), under the [MIT license](https://github.com/stblr/wuj5/blob/main/LICENSE).
- **[wii-code-tools](https://github.com/RoadrunnerWMC/wii-code-tools)**; created by [RoadrunnerWMC](https://github.com/RoadrunnerWMC), under the [MIT license](https://github.com/RoadrunnerWMC/wii-code-tools/blob/master/LICENSE).

[gpl-3.0]: https://www.gnu.org/licenses/gpl-3.0

## Contributing

This is primarily a personal project of mine that only involves me and people I directly want
to work with, but general patches and such from outside people are accepted!! Testing and issue
reporting are also very very much appreciated things!!

**We do NOT accept any code generated or written with assistance from LLMs.**
This is a passion project; machines cannot have passion.
