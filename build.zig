const std = @import("std");

pub fn build(b: *std.build.Builder) void {
    const target = b.standardTargetOptions(.{});
    const mode = b.standardReleaseOptions();

    const exe = b.addExecutable("snake-sdl", null);
    exe.setTarget(target);
    exe.setBuildMode(mode);
    exe.install();

    exe.linkLibC();
    exe.linkSystemLibrary("SDL2");

    exe.addCSourceFiles(&.{"src/main.c"}, &.{
        "-std=c11",
        "-pedantic",
        "-Wall",
        "-W",
        "-Wno-missing-field-initializers",
    });

    const run_cmd = exe.run();
    run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }
    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);
}
