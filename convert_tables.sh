# !/bin/bash
#
#
$(drush sql-connect) -e 'show tables' | while read TABLE;
do
  echo "Converting ${TABLE} to InnoDB and optimizing...";
  $(drush sql-connect) -e "ALTER TABLE \`${TABLE}\` ENGINE = INNODB; OPTIMIZE TABLE \`${TABLE}\`";
  echo "OK";
done;
