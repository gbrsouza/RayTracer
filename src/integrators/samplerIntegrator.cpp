#include "integrators/samplerIntegrator.h"

// [3] Enter the ray tracing main loop; this is the default render() method.
// Notice that the FlatIntegrator does not need to override this method.
// It relies on the version provided by the base class (SampleIntegrator).
void SamplerIntegrator::render( const Scene& scene ) {
    
    // Always call the preprocess() before doing any rendering.
    // This might be just an empty method, or not, depending on the integrator's needs.
    preprocess( scene );

    // This might just be a tile (part) of an image, rendered in parallel.
    Point2i img_dim = camera->get_film()->get_dimension();
    
    for ( int y = 0 ; y < img_dim.y() ; y++ ) {
        for( int x = 0 ; x < img_dim.x() ; x++ ) {
            
            Ray ray = camera->generate_ray( x, y ); // Generate the ray from (x,y)
            Color24 L = Li( ray, scene, *sampler );
            camera->get_film()->add_sampler( Point2i( x, y, 0 ), L ); // Set color of pixel (x,y) to L.
        }
    }

}