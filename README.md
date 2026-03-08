# voyager-qmk

ZSA Voyager 40-key firmware — Oryx layout with custom QMK features.

- [Oryx layout](https://configure.zsa.io/voyager/layouts/oB6Ww/latest/0)
- [How this works](https://blog.zsa.io/oryx-custom-qmk-features)
- Forked from [poulainpi/oryx-with-custom-qmk](https://github.com/poulainpi/oryx-with-custom-qmk)

## Usage

**Add custom QMK features** by editing files in `oB6Ww/` (`config.h`, `keymap.c`, `rules.mk`) per the [QMK docs](https://github.com/qmk/qmk_firmware/tree/master/docs/features). Commit and push to `main`.

**Edit layout in Oryx** as usual — add a note in the "Some notes about what you changed" field (used as the commit message), then click **Compile this layout**.

**Build firmware** by running the GitHub Action, then flash with [Keymapp](https://www.zsa.io/flash#flash-keymapp).
