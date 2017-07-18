<?php

/**
 * Admin form.
 */
function sms_outbound_add_more($form, &$form_state, $no_js_use = FALSE) {

  $form['#tree'] = TRUE;
  $form['services_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('SMS Outbound API Credentials'),
    '#prefix' => '<div id="services-fieldset-wrapper">',
    '#suffix' => '</div>',
  );
  $form['services_fieldset']['sms_outbound_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => variable_get('sms_outbound_username', 0),
  );
  $form['services_fieldset']['sms_outbound_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#default_value' => variable_get('sms_outbound_password', 0),
  );
  $form['services_fieldset']['sms_outbound_registration_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Registration message'),
    '#default_value' => variable_get('sms_outbound_registration_message', 0),
  );
  $form['services_fieldset']['sms_outbound_password_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Password recovery message'),
    '#default_value' => variable_get('sms_outbound_password_message', 0),
  );
  $form['services_fieldset']['sms_outbound_reminder_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Default reminder message'),
    '#default_value' => variable_get('sms_outbound_reminder_message', 0),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Final submit handler.
 *
 * Sets values were finally set.
 */
function sms_outbound_add_more_submit($form, &$form_state) {

  // If isset empty elements.
  if (in_array('', $form_state['values']['services_fieldset'])) {
    foreach ($form_state['values']['services_fieldset'] as $key=>$value) {
      if (!strlen($value)) {
        drupal_set_message($form['services_fieldset'][$key]['#title'] . t(' cannot be empty!'), 'error');
      }
    }
    return FALSE;
  }

  // If success.
  foreach ($form_state['values']['services_fieldset'] as $key=>$value) {
    variable_set($key, $value);
  }
  drupal_set_message(t('Saved SMS Outbound API Credentials'));
}
