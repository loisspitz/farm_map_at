<?php
/**
 * @file
 * farm_map_at.default_openlayers_sources.inc
 */

/**
 * Implements hook_default_openlayers_sources().
 */
function farm_map_at_default_openlayers_sources() {
  $export = array();

  // Generate a Basemap source.
  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'farm_map_at_source_basemap';
  $ol_source->name = 'Basemap';
  $ol_source->description = 'Basemap of Austria, based on government data.';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => 'http://maps1.wien.gv.at/basemap/geolandbasemap/normal/google3857/{z}/{y}/{x}.png',
  );
  $export['farm_map_at_source_basemap'] = $ol_source;

  // Generate a Basemap Orthofoto source.
  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'farm_map_at_source_basemaporthofoto';
  $ol_source->name = 'Basemap Orthofoto';
  $ol_source->description = 'Orthofoto layer provided by basemap.at. "Successor" of geoimage.at imagery.';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => 'https://maps1.wien.gv.at/basemap/bmaporthofoto30cm/normal/google3857/{z}/{y}/{x}.jpeg',
  );
  $export['farm_map_at_source_basemaporthofoto'] = $ol_source;

  return $export;
}
