<?php
/**
 * @file
 */

class DataStorageController extends EntityAPIController {
  /**
   * Loads requested records
   *
   * @return The results in a Traversable object.
   */
  public function query($ids, $conditions, $revision_id = FALSE) {
   return universal_data_storage_record_load_multiple($ids, $conditions);
  }

  /**
   * Permanently saves the given entity.
   *
   * In case of failures, an exception is thrown.
   *
   * @param $entity
   *   The entity to save.
   *
   * @return
   *   SAVED_NEW or SAVED_UPDATED is returned depending on the operation
   *   performed.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $transaction = isset($transaction) ? $transaction : db_transaction();
    try {
      // Load the stored entity, if any.
      if (!empty($entity->{$this->idKey}) && !isset($entity->original)) {
        // In order to properly work in case of name changes, load the original
        // entity using the id key if it is available.
        $entity->original = entity_load_unchanged($this->entityType, $entity->{$this->idKey});
      }
      $this->invoke('presave', $entity);

      if (!empty($entity->{$this->idKey}) && empty($entity->is_new)) {
        $return = universal_data_storage_record_save($entity);
        $this->resetCache(array($entity->{$this->idKey}));
        $this->invoke('update', $entity);
      }
      else {
        $return = universal_data_storage_record_save($entity);
        $this->invoke('insert', $entity);
      }
      // Ignore slave server temporarily.
      db_ignore_slave();
      unset($entity->is_new);
      unset($entity->original);

      return $return;
    }
    catch (Exception $e) {
      $transaction->rollback();
      watchdog_exception($this->entityType, $e);
      throw $e;
    }
  }

//  /**
//   * Implements EntityAPIControllerInterface.
//   *
//   * @param $transaction
//   *   Optionally a DatabaseTransaction object to use. Allows overrides to pass
//   *   in their transaction object.
//   */
//  public function delete($ids, DatabaseTransaction $transaction = NULL) {
////    $entities = $ids ? $this->load($ids) : FALSE;
////    if (!$entities) {
////      // Do nothing, in case invalid or no ids have been passed.
////      return;
////    }
////    // This transaction causes troubles on MySQL, see
////    // http://drupal.org/node/1007830. So we deactivate this by default until
////    // is shipped in a point release.
////    // $transaction = isset($transaction) ? $transaction : db_transaction();
//
//    try {
//      //$ids = array_keys($entities);
//
//      db_delete('universal_data_storage')
//        ->condition($this->idKey, $ids, 'IN')
//        ->execute();
//
////      db_delete('universal_data_storage_data')
////        ->condition($this->idKey, $ids, 'IN')
////        ->execute();
//
//      // Reset the cache as soon as the changes have been applied.
//      $this->resetCache($ids);
//
////      foreach ($entities as $id => $entity) {
////        $this->invoke('delete', $entity);
////      }
//      // Ignore slave server temporarily.
//      db_ignore_slave();
//    }
//    catch (Exception $e) {
//      if (isset($transaction)) {
//        $transaction->rollback();
//      }
//      watchdog_exception($this->entityType, $e);
//      throw $e;
//    }
//  }
}