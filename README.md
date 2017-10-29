# ergodox
my ergodox keymap.

# concept

My keymap has 3 layers.

Each layers are:

```
layer 0: normal keyboard layer, similar to US keyboard.

layer 1: handling cursor layer, move cursor like vim.

layer 2: mouse layer, emulate mouse, operate like vim.
```

## Each layer in details

### layer 0

This layer is normal keyboard.
I want to make it exactly the same to US keyboard.
But the number of keys of ergodox is different from normal one.
So I changed some symbol and functional keys from normal keyboard.

### layer 1

This layer is designed for vim's normal mode.
When you use this keymap, you'll get normal mode outside of vim.

### layer 2

This layer is mouse.
Cursor move is h,j,k,l like vim.
Mouse Wheel is y,u,i,o above to cursor.
Tab move is arrows.
Reset key is upper left.
Almost alphabet keys in right side are operate mouse and layer keys.
Almost alphabet keys in left side are cmd+self.

# how to change keymap.

1. generate url for change keymap in ergodox ez's site.

  ```
  $ ruby generate_url.rb
  ```

2. access generated url and modify keymap.

3. download `.c` and `.hex` files.

4. reset keyboard and apply `.hex` file.

5. commit and push `.c` and `.hex` files.