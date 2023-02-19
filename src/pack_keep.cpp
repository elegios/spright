
#include "packing.h"

namespace spright {

void pack_keep(const SheetPtr& sheet, SpriteSpan sprites,
    std::vector<Texture>& textures) {

  auto source_indices = std::map<ImagePtr, int>();
  for (auto& sprite : sprites) {
    const auto source_index = source_indices.emplace(
      sprite.source, to_int(source_indices.size())).first->second;
    sprite.texture_sheet_index = source_index;
    sprite.trimmed_rect = sprite.trimmed_source_rect;
    sprite.rect = sprite.source_rect;
  }

  create_textures_from_filename_indices(
    sheet, sprites, textures);

  for (auto& texture : textures)
    recompute_texture_size(texture);
}

} // namespace
