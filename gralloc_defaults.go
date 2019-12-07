package gralloc

import (
	"android/soong/android"
	"android/soong/cc"
)

func init() {
	// Register our own module type
	android.RegisterModuleType("gralloc_defaults", grallocDefaultsFactory)
}

func grallocDefaultsFactory() android.Module {
	module := cc.DefaultsFactory()

	// When the module is loaded, execute grallocDefaults
	android.AddLoadHook(module, grallocDefaults)

	return module
}

func grallocDefaults(ctx android.LoadHookContext) {
	gralloc1 := ctx.Config().VendorConfig("gralloc").Bool("use_v1")

	if gralloc1 {
		p := struct {
			Cflags []string
		}{
			[]string{"-DUSE_GRALLOC1"},
		}

		ctx.AppendProperties(&p)
	}
}
