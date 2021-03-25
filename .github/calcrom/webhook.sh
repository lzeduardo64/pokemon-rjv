#!/bin/bash -ex

build_name=$1
extension=_modern.gba
map_file=$build_name$extension
if [ ! -f $map_file ]; then
  echo "$map_file does not exist!"
  exit 1
fi

output=$(perl $(dirname "$0")/calcrom.pl $build_name.map | sed -E ':a;N;$!ba;s/\r{0,1}\n/\\n/g')
zip -r pokeemerald_modern.zip pokeemerald_modern.gba
bash $(dirname "$0")/discord.sh --webhook-url="$CALCROM_DISCORD_WEBHOOK_URL" --file pokeemerald_modern.zip --username "yooo" --text "teste123"
