<?php
/**
 * @file views-flipped-table.tpl.php
 * Template to display a view as a table with rows and columns flipped.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: The original array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $rows_flipped: An array of row items, with the original data flipped.
 *   $rows_flipped are keyed by field name, each item within a row is keyed
 *   by the original row number.
 * - $wrapper_classes: An array of classes to apply to each flipped row,
 *   indexed by the field name.
 * - $header_classes: An array of classes to apply to each row header,
 *   indexed by the field name.
 * - $field_classes: An array of classes to apply to each cell,
 *   indexed by the field name.
 * - $first_row_header: boolean indicating the first row is a table header.
 *
 * @ingroup views_templates
 */
?>
<table class="<?php print $classes; ?>">
  <?php if (!empty($title)) : ?>
    <caption><?php print $title; ?></caption>
  <?php endif; ?>

  <?php if ($first_row_header) : ?>
    <?php $field_names = array_keys($rows_flipped);
          $field_name = reset($field_names); ?>
    <thead>
      <tr class="<?php print($wrapper_classes[$field_name]); ?>">
        <th class="<?php print($header_classes[$field_name]); ?>">
          <?php print $header[$field_name] ?>
        </th>
        <?php foreach ($rows_flipped[$field_name] as $index => $item) : ?>
          <th class="<?php print($field_classes[$field_name][$index]); ?>">
            <?php print $item; ?>
          </th>
        <?php endforeach; ?>
      </tr>
    </thead>
    <?php array_shift($rows_flipped); ?>
  <?php endif; // $first_row_header ?>
  <tbody>
    <?php foreach ($rows_flipped as $field_name => $row) : ?>
      <tr class="<?php print $wrapper_classes[$field_name]; ?>">
        <th class="<?php print($header_classes[$field_name]); ?>">
          <?php echo $header[$field_name]; ?>
        </th>
        <?php foreach ($row as $index => $item): ?>
          <td class="<?php print($field_classes[$field_name][$index]); ?>">
            <?php echo $item; ?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>

