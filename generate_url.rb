# creae ergodox ez's keymap screen url for current version.

# return current version.
def current_version
  current_file = Dir.glob('./*.c').first
  current_file.split(/_|\./)[-2]
end

# join current version and url template.
def keymap_url(version)
  "http://configure.ergodox-ez.com/keyboard_layouts/#{version}/edit"
end

# ===================================================

puts keymap_url(current_version)