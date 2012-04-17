<?php
/**
 * @file
 *   This file holds helper functions for the islandora_viewers module.
 * @author
 *   William Panting
 */

/**
 * This function will return the selected viewer's theme function
 * given the known parameters
 * and setting provided in this module's admin page.
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
 * This function will query the database to get the mimetype mapping
 */
function islandora_viewers_get_mime_type_mapping() {
  $mimetype_mapping = array();
  $query = "SELECT * FROM {islandora_viewers_mime_type_mapping}";
  $result = db_query($query);

  while ($row = db_fetch_object($result)) {
    $mimetype_mapping[$row->mime_type] = $row->theme_function;
  }

  return $mimetype_mapping;
}
