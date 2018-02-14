# Enfold Child Framework

### Description
A framework for all current and future Louisville Geek enfold child themes.

## Quick Installation into a wordpress install
```
cd wp-content/themes
git clone https://github.com/louisvillegeek/enfold-child-starter.git enfold-child
```


### Installation
```
composer install
npm run build
```

### Watching

```
npm run watch
```


### Customizing

Add a shortcode/action/filter/enqueue to the given folders in the src directory.

Implement the base class/interface and add the class to the loader.


## Deploying 
When deploying a theme you must increment the version in the style.scss in assets/scss/style.scss.
This will cache bust the javascript and the style for the website.