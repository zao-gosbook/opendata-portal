(function ($) {
  Drupal.behaviors.od_cell_popup_popup = {
    attach: function (context, settings) {
      var check = $('.od-map-map-russia-wrapper').once('od-map-russia', drawMap);

      function drawMap() {
        var config = settings.od_map.russia;
        var width = 960,
          height = 500;

        // Setting color domains(intervals of values) for our map

        var color_domain = [50, 150, 350, 750, 1500]
        var ext_color_domain = [0, 50, 150, 350, 750, 1500]
        var legend_labels = ["< 50", "50+", "150+", "350+", "750+", "> 1500"]
        var color = d3.scale.threshold()
          .domain(color_domain)
          .range(["#adfcad", "#ffcb40", "#ffba00", "#ff7d73", "#ff4e40", "#ff1300"]);

        window.color = color;


        var wrapper = d3.select(".od-map-map-russia-wrapper");
        var infoDiv = wrapper.append('div')
          .attr('class', 'info-block')
          .style('opacity', 0);

        var svg = wrapper.append("svg")
          .attr("width", width)
          .attr("height", height)
          .style("margin", "10px auto");

        var projection = d3.geo.albers()
          .rotate([-105, 0])
          .center([-10, 65])
          .parallels([52, 64])
          .scale(700)
          .translate([width / 2, height / 2]);

        var path = d3.geo.path().projection(projection);

        //Reading map file and data
        queue()
          .defer(d3.json, config.map_json_path)
          .defer(d3.tsv, config.portals_tsv_path)
          .await(ready);

        //Start of Choropleth drawing

        function ready(error, map, data) {
          var portalsById = {};

          // Gather info
          data.forEach(function(d) {
            portalsById[d.region] = {
              'url': d.url,
              'text': d.text
            };
          });

          //Drawing Choropleth
          svg.append("g")
            .attr("class", "region")
            .selectAll("path")
            .data(topojson.object(map, map.objects.map).geometries)
            //.data(topojson.feature(map, map.objects.russia).features) <-- in case topojson.v1.js
            .enter().append("path")
            .attr("d", path)
            .attr("class", function(d) {
              return portalsById[d.properties.region] !== undefined ? 'has-portal' : 'no-portal'
            })
            .style("opacity", 0.8)

            //Adding mouseevents
            .on("mouseover", function(d) {
              // Show tooltip
              if (portalsById[d.properties.region] !== undefined) {
                var mouseCoords = d3.mouse(this);
                infoDiv.transition().duration(300)
                  .style("opacity", 1);

                infoDiv.html(portalsById[d.properties.region].text + '<span class="second">' + portalsById[d.properties.region].url + '</span>')
                  .style("left", String(Number(mouseCoords[0]) + Number(4)) + "px")
                  .style("top", String(Number(mouseCoords[1]) + Number(15)) + "px");
              }

              d3.select(this).transition().duration(300).style("opacity", 1);
            })
            .on("mouseout", function() {
              d3.select(this)
                .transition().duration(300)
                .style("opacity", 0.8);
              infoDiv.transition().duration(300)
                .style("opacity", 0);
            })

            // Adding click event handler
            .on('click', function(d) {
              if (portalsById[d.properties.region] !== undefined) {
                var win = window.open(portalsById[d.properties.region].url);
                win.focus();
              }
            });

          // Adding cities on the map

          d3.tsv(config.cities_tsv_path, function(error, data) {

            var city = svg.selectAll("g.city")
              .data(data)
              .enter()
              .append("g")
              .attr("class", function(d) { return "city city-code-" + d.Code; })
              .attr("transform", function(d) { return "translate(" + projection([d.lon, d.lat]) + ")"; })
              .attr('data-city-code', function(d) { return d.Code; });

            city.append("circle")
              .attr("r", 3)
              .attr('class', 'city-circle')
              //.style("fill", '#ffffff')
              //.style("opacity", 0.75);

            city.append("text")
              .attr('class', 'city-label')
              .attr("x", 5)
              .text(function(d) { return d.City; });
          });

        }; // <-- End of Choropleth drawing

  //      //Adding legend for our Choropleth
  //
  //      var legend = svg.selectAll("g.legend")
  //        .data(ext_color_domain)
  //        .enter().append("g")
  //        .attr("class", "legend");
  //
  //      var ls_w = 20, ls_h = 20;
  //
  //      legend.append("rect")
  //        .attr("x", 20)
  //        .attr("y", function(d, i){ return height - (i*ls_h) - 2*ls_h;})
  //        .attr("width", ls_w)
  //        .attr("height", ls_h)
  //        .style("fill", function(d, i) { return color(d); })
  //        .style("opacity", 0.8);
  //
  //      legend.append("text")
  //        .attr("x", 50)
  //        .attr("y", function(d, i){ return height - (i*ls_h) - ls_h - 4;})
  //        .text(function(d, i){ return legend_labels[i]; });
      }
    }
  }
}) (jQuery);