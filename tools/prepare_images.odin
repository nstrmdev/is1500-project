package main

import "core:fmt"
import "core:os"
import stbi "vendor:stb/image"

// Load an image at input_path and export the binary at output_path.
image_to_binary :: proc(input_path: cstring, output_path: cstring) {
	width, height, channels: i32

	// RGBA
	pixels := stbi.load(input_path, &width, &height, &channels, 4)
	if pixels == nil {
		fmt.printfln("[ERROR] Failed to load image '%s'", input_path)
		return
	}
	defer stbi.image_free(pixels)

	bytes := pixels[:int(width) * int(height) * 4]

	err := os.write_entire_file(string(output_path), bytes)
	if err != nil {
		fmt.printfln("[ERROR] Failed to write to sprite '%s'", output_path)
		return
	}

	fmt.printf("[INFO] Exported %i bytes to '%s'\n", len(bytes), output_path)
}

main :: proc() {
	player_input_path: cstring = "../assets/images/player.png"
	player_output_path: cstring = "../assets/compiled_images/player.bin"

	image_to_binary(player_input_path, player_output_path)
}
