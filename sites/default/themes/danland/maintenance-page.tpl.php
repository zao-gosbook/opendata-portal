<?php
// $Id: maintenance-page.tpl.php,v 1.1.2.2 2011/01/06 07:45:39 danprobo Exp $
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
<head>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>

<div>
<div id="header">
<div id="header-wrapper">
	<?php if ($logo): ?>
		<div id="logo-wrapper">
			<div class="logo">
				<a href="<?php print $base_path ?>" title="<?php print t('Home') ?>"><img src="<?php print $logo ?>" alt="<?php print t('Home') ?>" /></a>
			</div>
		</div><!-- end logo wrapper -->
	<?php endif; ?>
	<?php if ($site_name || $site_slogan) : ?>
		<div id="branding-wrapper">
			<?php if ($site_name) : ?>
					<h2 class="site-name"><a href="<?php print $base_path ?>" title="<?php print $site_name ?>"><?php print $site_name ?></a></h2>
			<?php endif; ?>
			<?php if ($site_slogan) : ?>
				<div class='site-slogan'><?php print $site_slogan; ?></div>
			<?php endif; ?>
        	</div><!-- end branding wrapper -->
	<?php endif; ?>

	<?php if ($feed_icons): ?>
		<div class="feed-wrapper">
			<?php print $feed_icons; ?>
		</div>
	<?php endif; ?>

	<?php if (!$is_admin): ?>
		<div id="authorize">
      		      <ul><?php global $user; if ($user->uid != 0) { print '<li class="first">' .t('Logged in as '). '<a href="' .url('user/'.$user->uid). '">' .$user->name. '</a></li>'; print '<li><a href="' .url('user/logout'). '">' .t('Logout'). '</a></li>'; } else { print '<li class="first"><a href="' .url('user'). '">' .t('Login'). '</a></li>'; print '<li><a href="' .url('user/register'). '">' .t('Register'). '</a></li>'; } ?></ul>
		</div>
	<?php endif; ?>

      </div><!-- end header-wrapper -->
</div> <!-- /header -->
<div style="clear:both"></div>

<div id="menu">
<div id="rounded-menu-left"></div>
<div id="rounded-menu-right"></div>
</div> <!-- end menu -->
<div style="clear:both"></div>

<div id="wrapper">
  <h1 class="title" id="page-title">
    <?php print $content; ?>
  </h1>
</div>

<div style="clear:both"></div>
<?php if ($show_messages) { print $messages; }; ?>

<div style="clear:both"></div>

</body>
</html>
