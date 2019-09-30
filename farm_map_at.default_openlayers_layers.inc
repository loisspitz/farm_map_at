<?php
/**
 * @file
 * farm_map_at.default_openlayers_layers.inc
 */

/**
 * Implements hook_default_openlayers_layers().
 */
function farm_map_at_default_openlayers_layers() {
  $export = array();

  // Basemap layer
  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE;
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'farm_map_at_layer_basemap';
  $ol_layer->name = 'Basemap';
  $ol_layer->description = 'Basemap of Austria, based on government data.';
  $ol_layer->factory_service = 'openlayers.Layer:Tile';
  $ol_layer->options = array(
    'source' => 'farm_map_at_source_basemap',
    'visible' => 0,
  );
  $export['farm_map_at_layer_basemap'] = $ol_layer;

  // Basemap Orthofoto layer
  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE;
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'farm_map_at_layer_basemaporthofoto';
  $ol_layer->name = 'Basemap Orthofoto';
  $ol_layer->description = 'Orthofoto layer provided by basemap.at. "Successor" of geoimage.at imagery.';
  $ol_layer->factory_service = 'openlayers.Layer:Tile';
  $ol_layer->options = array(
    'source' => 'farm_map_at_source_basemaporthofoto',
    'visible' => 0,
  );
  $export['farm_map_at_layer_basemaporthofoto'] = $ol_layer;

  return $export;
}

/**
 * Implements hook_default_openlayers_layers_alter().
 */
function farm_map_at_default_openlayers_layers_alter(&$layers) {

  // Add Kartverket layers to farm_map_layer_group.
  if (!empty($layers['farm_map_layer_group'])) {

    // Create a list of Openlayers layer names.
    $ol_layers = array();

    // Add the layers
    $ol_layers[] = 'farm_map_at_layer_basemap';
    $ol_layers[] = 'farm_map_at_layer_basemaporthofoto';

    // Merge into existing layers.
    $existing_layers = $layers['farm_map_layer_group']->options['grouplayers'];
    $layers['farm_map_layer_group']->options['grouplayers'] = array_merge($ol_layers, $existing_layers);
  }
}

