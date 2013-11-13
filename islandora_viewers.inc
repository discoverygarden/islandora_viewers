<?php

/**
 * @file
 * This file holds helper functions for the islandora_viewers module.
 *
 * @author
 * William Panting
 */

/**
 * Returns the appropriate theme function.
 *
 * Function is selected according the known parameters and settings provided
 * in this module's admin page.
 *
 * @TODO: grow as new options are added to the module's admin page
 *
 * @param string $mime_type
 *   The mime type to find the theme function to call for a viewer.
 *
 * @return mixed
 *   string of the theme function that can be called for a viewer
 *   null if there are no settings set
 */
function islandora_viewers_get_viewer_theme($mime_type) {
  $mime_type_mapping = islandora_viewers_get_mime_type_mapping();
  return isset($mime_type_mapping[$mime_type]) ? $mime_type_mapping[$mime_type] : NULL;
}

/**
 * This function will query the database to get the mimetype mapping.
 */
function islandora_viewers_get_mime_type_mapping() {
  $mimetype_mapping = array();
  $query = db_select('islandora_viewers_mime_type_mapping', 't');
  $query->fields('t', array());
  $results = $query->execute();

  foreach ($results as $result) {
    $mimetype_mapping[$result->mime_type] = $result->theme_function;
  }

  return $mimetype_mapping;
}
