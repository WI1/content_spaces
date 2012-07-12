<?php

/**
 * Implementation of hook_views_handlers().
 */
function content_spaces_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'content_spaces'),
    ),
    'handlers' => array(
      'spaces_handler_field_content' => array('parent' => 'content_handler_field_multiple'),
    ),
  );
}


/**
 * Implementation of hook_views_data_alter().
 */
function content_spaces_views_data_alter(&$data) {
  // Iterate through Views data and replace instances of
  // content_handler_field_multiple with content_spaces node handler.
  foreach ($data as $table => $data_table) {
    foreach ($data_table as $field => $data_field) {
      if (isset($data_field['field']['handler']) && $data_field['field']['handler'] === 'content_handler_field_multiple') {
        $data[$table][$field]['field']['handler'] = 'spaces_handler_field_content';
      }
    }
  }
}
