#!/bin/bash -ex

build_name=$1
extension=_modern.gba
map_file=$build_name$extension
if [ ! -f $map_file ]; then
  echo "$map_file does not exist!"
  exit 1
fi

zip -r $build_name.zip $map_file
bash $(dirname "$0")/discord.sh --webhook-url="$DISCORD_WEBHOOK" --text "rom atual do github" --file $build_name.zip
