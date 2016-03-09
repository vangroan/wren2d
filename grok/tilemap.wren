


class Tile {
    construct new(gid) {
	// The id of the tile type in the set
	_gid = gid
    }
    
    gid { _gid }
}


class Tilemap {
    construct new(width, height, tilewidth, tileheight) {
	_width = width
	_height = height
	_tilewidth = tilewidth
	_tileheight = tileheight
	
	_tileset = []
	_data = [width * height]
    }
    
    get(i, j) {
	return _tileset[_data[i + j * _width]]
    }
    
    setTileType(tile) {
	_tileset[tile.gid] = tile
    }
}

// =====
// Tests
// =====

